#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <functional>
#include <string>
#include <fstream>
#include <codecvt>
#include <locale>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>
#include <boost/iostreams/stream.hpp> 
#include <boost/iostreams/categories.hpp>  
#include <boost/iostreams/code_converter.hpp>
#include <boost/locale.hpp> 

namespace JSON_TASK {

using namespace boost::property_tree;
using namespace System;
/*
クラス名 JSON_Task 
概要 : JSONパーサでツリー構造にした文字列を取り出します。これを表にするためにkey名をコントロールの座標とした
mapに変換するためのクラス
コントロールの座標 (x,y) -> std;;string 座標 = "x.y"; とするイメージ
作成日 : 2017年9月2日
作成者 : 平澤敬介
*/
class JSON_Task {

public :
	//JSONパーサでツリー構造にしたオブジェクトを操作するためのオブジェクト
	std::map<std::string, std::vector<std::string>> JSON_map;
	//デフォルトコンストラスタ
	JSON_Task() {};
	//コンストラスタ 作成したmapをメンバに加える
	JSON_Task(std::map<std::string, std::vector<std::string>> map)
		: JSON_map(map) {};

	/*
	関数名 : JSON_map
	概要   : ツリー構造のデータからコントロールの座標名をkeyとしたmapを作成する作成する関数
	引数   : ptree pt ツリー構造のデータ, std::vector<std::string> tmp 加算する配列
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	void create_map(ptree pt, std::vector<std::string> tmp) {

		//配列の要素数を調べるカウンタ
		int count = 0;
		//配列要素走査用のツリー構造オブジェクト
		ptree array_pt;

		//イテレータを使い末尾まで走査する
		BOOST_FOREACH(const boost::property_tree::ptree::value_type& e, pt) {

			//配列構造の判定式 配列の場合 value のキー名が空になっているはず
			if (e.first.empty()) {


				//確認用
				count++;
				std::cout << "\n" << "要素数" << count << "\n";

				//オブジェクト構造なのか判定
				if (0 < e.second.size()) {
					//オブジェクトの場合イテレータで操作してキー名と値を入れる
					BOOST_FOREACH(const boost::property_tree::ptree::value_type& array_object, e.second) {
						//key名を入れる
						tmp.push_back(array_object.first);
						//値を入れる
						tmp.push_back(array_object.second.data());
					}
					//配列の識別用の文字を入れる
					tmp.push_back("This_is_an_array_element");
					//value 要素か判定
				}
				else {
					//値を入れる
					tmp.push_back(e.second.data());
					//配列の識別用の文字を入れる
					tmp.push_back("This_is_an_array_element");
				}







				//確認用　Value と 配列の2か所
				//この時点で配列には階層となるkey名が入っている イテレータでkey名を走査
				for (std::vector<std::string>::iterator itr = tmp.begin(); itr != tmp.end(); itr++) {

					//テスト用コンソールに表示
					std::cout << *itr << " ";
				}
				std::cout << "\n";

				//オブジェクト構造なのか判定
				if (0 < e.second.size()) {
					//次の要素に備えて不要な値を取り出す
					tmp.pop_back();
					tmp.pop_back();
					tmp.pop_back();

					//value 要素か判定
				}
				else {
					//次の要素に備えて不要な値を取り出す
					tmp.pop_back();
					tmp.pop_back();
				}

				//オブジェクト構造の判定式 オブジェクトの場合 secondの要素のsize が1以上になっているはず
			}
			else if (0 < e.second.size()) {

				//配列にキー名を追加する
				tmp.push_back(e.first);
				//再帰処理を行う
				create_map(e.second, tmp);
				//キー名を取り出す
				tmp.pop_back();
				//それ以外の場合 value要素のはず
			}
			else {
				//key名を入れる
				tmp.push_back(e.first);
				//値を入れる
				tmp.push_back(e.second.data());




				//確認用　Value と 配列の2か所
				//この時点で配列には階層となるkey名が入っている イテレータでkey名を走査
				for (std::vector<std::string>::iterator itr = tmp.begin(); itr != tmp.end(); itr++) {

					//テスト用コンソールに表示
					std::cout << *itr << " ";
				}
				std::cout << "\n";

				//次の要素に備えて値を取り出す
				tmp.pop_back();
				tmp.pop_back();
			}
		}
	}
	/*
	関数名 : output_array
	概要   : コントロールの座標文字をkeyとして配列を取り出す
	引数   : コントロールの座標文字
	返却値 : mapに入っている配列
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/

	/*
	関数名 : put_map
	概要   : key名と配列を指定してmapに加える
	引数   : std::string コントロールの座標文字,std::vector<std::string> vec加える配列
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/

	/*
	関数名 : Convert_String
	概要   : std::string 文字列を System::String^文字列に文字コードを指定して変換する
	引数   : std::string 文字列 System::Text::Encoding^ エンコーディング
	参照   : http://d.hatena.ne.jp/It_lives_vainly/20070824/1187947992
	返却値 : System::String^文字列
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	String^ Convert_String(const std::string& i_src,System::Text::Encoding^ i_encoding) {
		//エンコーディングを指定して新しくString^型の文字列を生成する
		return  gcnew System::String(i_src.data(), 0, i_src.size(), i_encoding);
	}
	/*
	関数名 : Convert_string
	概要   : System::String 文字列を std::string 文字列に文字コードを指定して変換する
	引数   : System::String 文字列 System::Text::Encoding^ エンコーディング
	参照   : http://d.hatena.ne.jp/It_lives_vainly/20070824/1187947992
	返却値 : std::string 文字列
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	std::string Convert_string(System::String^ i_src, System::Text::Encoding^ i_encoding) {
		//変換した文字列を補完する変数
		std::string a_str;

		//判定式
		if (i_src != nullptr &&  i_src->Length > 0) {
			//変換するために一時的にbyte で保管する
			array< Byte >^ a_array = System::Text::Encoding::Convert(
				System::Text::Encoding::Unicode,		// 変換元エンコーディング
				i_encoding,								// 変換先エンコーディング
				System::Text::Encoding::Unicode->GetBytes(i_src));
			//
			pin_ptr<Byte> a_pin = &a_array[0];
			a_str.assign(reinterpret_cast<char*>(a_pin), a_array->Length);
		}
		//String^ から std::string に変換 
		return a_str;
	}
	/*
	関数名 : erace_map
	概要   : key名を指定してmapから取り除く
	引数   : std::string コントロールの座標文字
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/

	/*
	関数名 : init
	概要   : データを初期化する
	引数   : 無し
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
};
}