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
#include <boost/lexical_cast.hpp>
#include <boost/iostreams/stream.hpp> 
#include <boost/iostreams/categories.hpp>  
#include <boost/iostreams/code_converter.hpp>
#include <boost/locale.hpp> 

namespace JSON_TASK {

using namespace boost::property_tree;
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
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
	//コントロールの座標文字
	std::string coordinate = "";
	//コントロールの座標文字を作成する変数 x y
	int x_position = 0;
	int y_position = 0;
	//コントロールの座標の最大値
	int max_x_position = 0;
	int max_y_position = 0;
	//配列要素の識別し
	std::string array_identi = "This_is_an_array_element";
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
					tmp.push_back(this->array_identi);
					//value 要素か判定
				}
				else {
					//値を入れる
					tmp.push_back(e.second.data());
					//配列の識別用の文字を入れる
					tmp.push_back(this->array_identi);
				}

				//座標文字を作成
				this->coordinate = this->create_coordinate(this->x_position, y_position);
				//実際にmapに追加
				this->JSON_map[this->coordinate] = tmp;

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
				//x座標を更新
				this->x_position++;

			//オブジェクト構造の判定式 オブジェクトの場合 secondの要素のsize が1以上になっているはず
			} else if (0 < e.second.size()) {

				//配列にキー名を追加する
				tmp.push_back(e.first);
				//再帰処理を行う
				create_map(e.second, tmp);
				//キー名を取り出す
				tmp.pop_back();
				//最大値を更新する
				if (max_x_position < x_position) {
					this->max_x_position = x_position;
				}
				//座標を更新
				this->x_position = 0;
				this->y_position++;
				//y軸の最大値を更新
				this->max_y_position = this->y_position;
				//それ以外の場合 value要素のはず
			}
			else {
				//key名を入れる
				tmp.push_back(e.first);
				//値を入れる
				tmp.push_back(e.second.data());

				//座標文字を作成
				this->coordinate = this->create_coordinate(this->x_position,y_position);
				//実際にmapに追加
				this->JSON_map[this->coordinate] = tmp;
				//次の要素に備えて値を取り出す
				tmp.pop_back();
				tmp.pop_back();
				//x座標を更新する
				this->x_position++;
			}
		}
	}
	/*
	関数名 : create_coordinate
	概要   : コントロールの座標文字を作成する
	引数   : int x,y コントロールの座標
	返却値 : std::string 座標文字
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	std::string create_coordinate(int x, int y) {
		//座標文字を返却 ->  x.y の形
		return boost::lexical_cast<std::string>(x) + "." + boost::lexical_cast<std::string>(y);
	}
	/*
	関数名 : max_position_x
	概要   : x軸の最大値を返す
	引数   : 無し
	返却値 : x軸の最大値
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	int max_position_x() const {

		return this->max_x_position;
	}
	/*
	関数名: max_position_y
	概要 : y軸の最大値を返す
	引数 : 無し
	返却値 : y軸の最大値
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	int max_position_y() const {

		return this->max_y_position;
	}

	/*
	関数名 : init_X_Y
	概要   : コントロールの座標文字を初期化する
	引数   : 無し
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	void init_X_Y() {
		//座標を(0,0)に設定
		this->x_position = 0;
		this->y_position = 0;
	}

	/*
	関数名 : output_array
	概要   : コントロールの座標文字をkeyとして配列を取り出す
	引数   : コントロールの座標文字
	返却値 : mapに入っている配列
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	std::vector<std::string> output_array(std::string coordinate) {
		
		return this->JSON_map[coordinate];
	}
	/*
	関数名 : put_map
	概要   : key名と配列を指定してmapに加える
	引数   : std::string コントロールの座標文字,std::vector<std::string> vec加える配列
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	void put_map(std::string coordinate, std::vector<std::string> vec) {

		this->JSON_map[coordinate] = vec;
	}
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
	void erace_map(std::string coordinate) {
		//イテレータで位置を特定する
		auto itr = this->JSON_map.find(coordinate);
		//key名の値が入っているか確認する
		if (itr != this->JSON_map.end()) {
			//入っているならば削除する
			this->JSON_map.erase(itr);
		}
		else {
			//エラーメッセージを表示する
			MessageBox::Show("削除できませんでした");
		}
	}
	/*
	関数名 : init
	概要   : データを初期化する
	引数   : 無し
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
	void init() {
		//mapを初期化
		this->JSON_map.erase(this->JSON_map.begin(),this->JSON_map.end());
	}
};
}