#pragma once
#include "JSON_Task.h"
#include <iostream>
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

namespace Make_Application {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace boost::property_tree;

	/// <summary>
	/// Basic の概要
	/// </summary>
	public ref class Basic : public System::Windows::Forms::Form
	{
	public:
		Basic(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Basic()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Label^  DB名;
	private: System::Windows::Forms::Label^  クエリ;
	private: System::Windows::Forms::Label^  JSON名;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  DB;
	private: System::Windows::Forms::TextBox^  Query;
	private: System::Windows::Forms::TextBox^  JSON;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->DB名 = (gcnew System::Windows::Forms::Label());
			this->クエリ = (gcnew System::Windows::Forms::Label());
			this->JSON名 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->DB = (gcnew System::Windows::Forms::TextBox());
			this->Query = (gcnew System::Windows::Forms::TextBox());
			this->JSON = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// DB名
			// 
			this->DB名->AutoSize = true;
			this->DB名->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->DB名->Location = System::Drawing::Point(80, 49);
			this->DB名->Name = L"DB名";
			this->DB名->Size = System::Drawing::Size(47, 16);
			this->DB名->TabIndex = 3;
			this->DB名->Text = L"DB名";
			// 
			// クエリ
			// 
			this->クエリ->AutoSize = true;
			this->クエリ->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->クエリ->Location = System::Drawing::Point(84, 107);
			this->クエリ->Name = L"クエリ";
			this->クエリ->Size = System::Drawing::Size(43, 16);
			this->クエリ->TabIndex = 4;
			this->クエリ->Text = L"クエリ";
			// 
			// JSON名
			// 
			this->JSON名->AutoSize = true;
			this->JSON名->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->JSON名->Location = System::Drawing::Point(58, 162);
			this->JSON名->Name = L"JSON名";
			this->JSON名->Size = System::Drawing::Size(69, 16);
			this->JSON名->TabIndex = 5;
			this->JSON名->Text = L"JSON名";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// DB
			// 
			this->DB->Location = System::Drawing::Point(242, 49);
			this->DB->Name = L"DB";
			this->DB->Size = System::Drawing::Size(498, 19);
			this->DB->TabIndex = 6;
			// 
			// Query
			// 
			this->Query->Location = System::Drawing::Point(242, 108);
			this->Query->Name = L"Query";
			this->Query->Size = System::Drawing::Size(498, 19);
			this->Query->TabIndex = 7;
			// 
			// JSON
			// 
			this->JSON->Location = System::Drawing::Point(242, 159);
			this->JSON->Name = L"JSON";
			this->JSON->Size = System::Drawing::Size(498, 19);
			this->JSON->TabIndex = 8;
			this->JSON->DoubleClick += gcnew System::EventHandler(this, &Basic::JSON_DoubleClick);
			// 
			// Basic
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(871, 358);
			this->Controls->Add(this->JSON);
			this->Controls->Add(this->Query);
			this->Controls->Add(this->DB);
			this->Controls->Add(this->JSON名);
			this->Controls->Add(this->クエリ);
			this->Controls->Add(this->DB名);
			this->Name = L"Basic";
			this->Text = L"Basic";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//System::String^からstd::string に変換する関数
	//参照 https://msdn.microsoft.com/ja-jp/library/1b4az623.aspx
	std::string ToStdString(System::String^ i_src,System::Text::Encoding^ i_encoding) {
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

	//ファイルを読み込むイベント
	private: System::Void JSON_DoubleClick(System::Object^  sender, System::EventArgs^  e) {

		//ファイルを選択するダイアログを表示する
		openFileDialog1->ShowDialog();
		//ダイアログから取得したファイル名 
		this->JSON->Text = openFileDialog1->FileName;
		//ファイル名を変数に保管
		String^ fileName = this->JSON->Text;
		//ファイルを開けなかったとき様に例外処理
		try {
			//エンコーディング設定部分
			std::wcout.imbue(std::locale(""));
			//ファイルを開ける文字コードに変換 Shift-JIS
			System::Text::Encoding^ enc = System::Text::Encoding::GetEncoding(0);
			//std::string 型に文字列を変換
			std::string set_path = ToStdString(fileName, enc);
			//確認用 コンソール上にファイルパスを表示
			std::cout << set_path << "\n";

			// ファイルオープン
			std::ifstream ifs(set_path);

			// エンコーディングを指定
			ifs.imbue(std::locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t>));
			//ファイルを開けたのか判定する。
			if (!ifs) {
				//開けなかった場合処理を終了する
				std::cerr << "cannot open file" << std::endl;
				return;
			}

			//JSON読み込み用のオブジェクト
			boost::property_tree::ptree pt;
			//実際にJSONファイルを読み込みツリー構造にする
			boost::property_tree::json_parser::read_json(ifs, pt);

			//メンバのマップに追加する可変長配列
			std::vector<std::string> map_substitute;
			create_map(pt, map_substitute);

			write_json("data_out.json", pt, std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
			//ファイルを取得できなかったとき様
		} catch (Exception^ e) {
			//エラー種類で分岐 ファイルが見つからない
			if (dynamic_cast<FileNotFoundException^>(e)) {

				//見つからないファイル名を表示する
				Console::WriteLine("file '{0}' not found", fileName);
			//別の理由の場合
			} else {
				//JSONファイルではない可能性が高い
				Console::WriteLine("problem reading file '{0}'", fileName);
			}	
		}

		//ダイアログを閉じる
		this->Close();
	}
		//boostのツリー構造データから文字列を取得して可変長配列に入れる
		//value に到達したならばメンバのマップに追加する関数をコールする
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
					} else {
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
					} else {
						//次の要素に備えて不要な値を取り出す
						tmp.pop_back();
						tmp.pop_back();
					}

				//オブジェクト構造の判定式 オブジェクトの場合 secondの要素のsize が1以上になっているはず
				} else if (0 < e.second.size()) {

					//配列にキー名を追加する
					tmp.push_back(e.first);
					//再帰処理を行う
					create_map(e.second, tmp);
					//キー名を取り出す
					tmp.pop_back();
				//それ以外の場合 value要素のはず
				} else {
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
};
}
