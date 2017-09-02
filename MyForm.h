#pragma once
#include "Basic.h"
#include "JSON_Task.h"
#include "Detailed_dialog.h"

namespace Make_Application {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  基本ToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  Tab_Select;
	private: System::Windows::Forms::TabPage^  Grid_Tab;



	private: System::Windows::Forms::TabPage^  List_Tab;

	private: System::Windows::Forms::Button^  キャンセル;

	private: System::Windows::Forms::Button^  作成;

	private: System::Windows::Forms::Button^  OK;
	private: System::Windows::Forms::TextBox^  横BOX;

	private: System::Windows::Forms::TextBox^  縦BOX;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ヨコBOX;

	private: System::Windows::Forms::TextBox^  タテBOX;
	private: System::Windows::Forms::Label^  ヨコ;


	private: System::Windows::Forms::Label^  タテ;
	private: System::Windows::Forms::TableLayoutPanel^  grid_table;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->基本ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Tab_Select = (gcnew System::Windows::Forms::TabControl());
			this->Grid_Tab = (gcnew System::Windows::Forms::TabPage());
			this->キャンセル = (gcnew System::Windows::Forms::Button());
			this->作成 = (gcnew System::Windows::Forms::Button());
			this->OK = (gcnew System::Windows::Forms::Button());
			this->横BOX = (gcnew System::Windows::Forms::TextBox());
			this->縦BOX = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->List_Tab = (gcnew System::Windows::Forms::TabPage());
			this->ヨコBOX = (gcnew System::Windows::Forms::TextBox());
			this->タテBOX = (gcnew System::Windows::Forms::TextBox());
			this->ヨコ = (gcnew System::Windows::Forms::Label());
			this->タテ = (gcnew System::Windows::Forms::Label());
			this->grid_table = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->menuStrip1->SuspendLayout();
			this->Tab_Select->SuspendLayout();
			this->Grid_Tab->SuspendLayout();
			this->List_Tab->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->基本ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(860, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 基本ToolStripMenuItem
			// 
			this->基本ToolStripMenuItem->Name = L"基本ToolStripMenuItem";
			this->基本ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->基本ToolStripMenuItem->Text = L"基本";
			this->基本ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::基本ToolStripMenuItem_Click);
			// 
			// Tab_Select
			// 
			this->Tab_Select->Controls->Add(this->Grid_Tab);
			this->Tab_Select->Controls->Add(this->List_Tab);
			this->Tab_Select->Location = System::Drawing::Point(12, 27);
			this->Tab_Select->Name = L"Tab_Select";
			this->Tab_Select->SelectedIndex = 0;
			this->Tab_Select->Size = System::Drawing::Size(836, 448);
			this->Tab_Select->TabIndex = 1;
			// 
			// Grid_Tab
			// 
			this->Grid_Tab->AutoScroll = true;
			this->Grid_Tab->Controls->Add(this->キャンセル);
			this->Grid_Tab->Controls->Add(this->作成);
			this->Grid_Tab->Controls->Add(this->OK);
			this->Grid_Tab->Controls->Add(this->横BOX);
			this->Grid_Tab->Controls->Add(this->縦BOX);
			this->Grid_Tab->Controls->Add(this->label2);
			this->Grid_Tab->Controls->Add(this->label1);
			this->Grid_Tab->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Grid_Tab->Location = System::Drawing::Point(4, 22);
			this->Grid_Tab->Name = L"Grid_Tab";
			this->Grid_Tab->Padding = System::Windows::Forms::Padding(3);
			this->Grid_Tab->Size = System::Drawing::Size(828, 422);
			this->Grid_Tab->TabIndex = 0;
			this->Grid_Tab->Text = L"グリッド";
			this->Grid_Tab->UseVisualStyleBackColor = true;
			// 
			// キャンセル
			// 
			this->キャンセル->Location = System::Drawing::Point(703, 19);
			this->キャンセル->Name = L"キャンセル";
			this->キャンセル->Size = System::Drawing::Size(75, 23);
			this->キャンセル->TabIndex = 6;
			this->キャンセル->Text = L"キャンセル";
			this->キャンセル->UseVisualStyleBackColor = true;
			// 
			// 作成
			// 
			this->作成->Location = System::Drawing::Point(597, 19);
			this->作成->Name = L"作成";
			this->作成->Size = System::Drawing::Size(75, 23);
			this->作成->TabIndex = 5;
			this->作成->Text = L"作成";
			this->作成->UseVisualStyleBackColor = true;
			this->作成->Click += gcnew System::EventHandler(this, &MyForm::作成_Click);
			// 
			// OK
			// 
			this->OK->Location = System::Drawing::Point(493, 19);
			this->OK->Name = L"OK";
			this->OK->Size = System::Drawing::Size(75, 23);
			this->OK->TabIndex = 4;
			this->OK->Text = L"OK";
			this->OK->UseVisualStyleBackColor = true;
			this->OK->Click += gcnew System::EventHandler(this, &MyForm::OK_Click);
			// 
			// 横BOX
			// 
			this->横BOX->Location = System::Drawing::Point(36, 27);
			this->横BOX->Name = L"横BOX";
			this->横BOX->Size = System::Drawing::Size(100, 19);
			this->横BOX->TabIndex = 3;
			// 
			// 縦BOX
			// 
			this->縦BOX->Location = System::Drawing::Point(36, 6);
			this->縦BOX->Name = L"縦BOX";
			this->縦BOX->Size = System::Drawing::Size(100, 19);
			this->縦BOX->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ヨコ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"タテ";
			// 
			// List_Tab
			// 
			this->List_Tab->Controls->Add(this->ヨコBOX);
			this->List_Tab->Controls->Add(this->タテBOX);
			this->List_Tab->Controls->Add(this->ヨコ);
			this->List_Tab->Controls->Add(this->タテ);
			this->List_Tab->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->List_Tab->Location = System::Drawing::Point(4, 22);
			this->List_Tab->Name = L"List_Tab";
			this->List_Tab->Padding = System::Windows::Forms::Padding(3);
			this->List_Tab->Size = System::Drawing::Size(828, 422);
			this->List_Tab->TabIndex = 1;
			this->List_Tab->Text = L"リスト";
			this->List_Tab->UseVisualStyleBackColor = true;
			// 
			// ヨコBOX
			// 
			this->ヨコBOX->Location = System::Drawing::Point(34, 27);
			this->ヨコBOX->Name = L"ヨコBOX";
			this->ヨコBOX->Size = System::Drawing::Size(100, 19);
			this->ヨコBOX->TabIndex = 7;
			// 
			// タテBOX
			// 
			this->タテBOX->Location = System::Drawing::Point(34, 6);
			this->タテBOX->Name = L"タテBOX";
			this->タテBOX->Size = System::Drawing::Size(100, 19);
			this->タテBOX->TabIndex = 6;
			// 
			// ヨコ
			// 
			this->ヨコ->AutoSize = true;
			this->ヨコ->Location = System::Drawing::Point(4, 30);
			this->ヨコ->Name = L"ヨコ";
			this->ヨコ->Size = System::Drawing::Size(23, 12);
			this->ヨコ->TabIndex = 5;
			this->ヨコ->Text = L"ヨコ";
			// 
			// タテ
			// 
			this->タテ->AutoSize = true;
			this->タテ->Location = System::Drawing::Point(4, 9);
			this->タテ->Name = L"タテ";
			this->タテ->Size = System::Drawing::Size(24, 12);
			this->タテ->TabIndex = 4;
			this->タテ->Text = L"タテ";
			// 
			// grid_table
			// 
			this->grid_table->AutoSize = true;
			this->grid_table->Location = System::Drawing::Point(8, 52);
			this->grid_table->Name = L"grid_table";
			this->grid_table->Size = System::Drawing::Size(836, 375);
			this->grid_table->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(860, 487);
			this->Controls->Add(this->Tab_Select);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->Tab_Select->ResumeLayout(false);
			this->Grid_Tab->ResumeLayout(false);
			this->Grid_Tab->PerformLayout();
			this->List_Tab->ResumeLayout(false);
			this->List_Tab->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		//縦の数値を保管する変数
		int Vertical = 0;
		//横の数値を保管する変数
		int Side = 0;
		//エンコーディング std::string -> SystemStrig^用
		System::Text::Encoding^ to_System = System::Text::Encoding::GetEncoding(65001);
		//エンコーディング SystemStrig^ -> std::string用
		System::Text::Encoding^ to_std = System::Text::Encoding::GetEncoding(0);
		//動的に生成するテキストBOX
		System::Windows::Forms::TextBox^  panel;
		//基本ダイアログを開くオブジェクト
		ref class Basic^ basic;
		//詳細ダイアログを開くオブジェクト
		ref class Detailed_dialog^ Detailed_Dialog;
		//JSON処理を行うためのクラスオブジェクト
		JSON_Task* output_table;

		//表を作成しJSONの値を配置する
	   //OKボタンをクリックしたときに縦横の値を読み取りtableのcolumn row に割り当てる
	private: System::Void OK_Click(System::Object^  sender, System::EventArgs^  e) {

		//文字が含まれていたり Int型で表現できない数値の場合例外が発生するため try catch で囲う
		try {
			//縦の数値文字をint型整数に変換
			this->Vertical = Convert::ToInt32(this->縦BOX->Text);
			//横の数値文字をint型整数に変換
			this->Side = Convert::ToInt32(this->横BOX->Text);

			//縦横の値が大きすぎるとオーバーフローするため
			if (400 <= this->Vertical * this->Side) {
				//警告文
				MessageBox::Show("表を表示しきれません");
				return;
			}

			//実際に表の横の長さを決める
			this->grid_table->ColumnCount = this->Side;
			//実際に表の縦の長さを決める
			this->grid_table->RowCount = this->Vertical;
			//設定した内容を表示
			MessageBox::Show("縦" + this->Vertical + "列\n" + "横" + this->Side + "行で設定します");
		}
		//文字が含まれている場合 例外をキャッチ
		catch (FormatException^ ex) {
			//エラーメッセージ
			MessageBox::Show("数値を入力してください");
			return;
		}
	}
			 //実際に表を作成
	private: System::Void 作成_Click(System::Object^  sender, System::EventArgs^  e) {

		//テキストボックスに縦横の整数を入力しているか調べる
		if (this->Vertical == 0 || this->Side == 0) {
			//警告文
			MessageBox::Show("配列の要素数を決めてください");
			return;
		}
		//表の縦の値をセット
		this->grid_table->RowCount = this->Vertical;
		//表の横の値をセット
		this->grid_table->ColumnCount = this->Side;

		//列の走査
		for (int j = 0; j < this->grid_table->RowCount; j++) {
			//行の走査
			for (int i = 0; i < this->grid_table->ColumnCount; i++) {
				//TextBox を新たに生成
				this->panel = gcnew TextBox();
				//TextBoxの大きさを決定
				this->panel->Size = System::Drawing::Size(100, 30);
				//セルのダブルクリックイベントを設定
				this->panel->DoubleClick += gcnew System::EventHandler(this, &MyForm::Panel_DoubleClick);
				//テーブルにTextBoxを追加
				this->grid_table->Controls->Add(this->panel, i, j);
			}
		}
		//表を生成する
		this->Grid_Tab->Controls->Add(this->grid_table);
	}
	//各コントロールをクリックしたときのイベント
	//ダイアログを表示しJSONの詳細を表示し、
	//OKボタン押下でメンバのmapを変更する
	private: System::Void Panel_DoubleClick(System::Object^  sender, System::EventArgs^  e) {

		//座標取得
		int y_p = this->grid_table->GetCellPosition((TextBox^)sender).Row;
		int x_p = this->grid_table->GetCellPosition((TextBox^)sender).Column;
		//key名となる座標文字を取得
		std::string coordinate = this->output_table->create_coordinate(x_p, y_p);
		//ダブルクリックした場所の配列の要素数
		int row = this->output_table->JSON_map[coordinate].size();

		//配列を末端まで走査して文字列を表にする
		for (auto itr = this->output_table->JSON_map[coordinate].begin();
			itr != this->output_table->JSON_map[coordinate].end(); itr++) {

		}

		//詳細ダイアログの生成
		this->Detailed_Dialog = gcnew Detailed_dialog();
		//一列の表を作成する
		this->Detailed_Dialog->Detailed->ColumnCount = 1;
		//最低でも 1 以上設定する
		this->Detailed_Dialog->Detailed->RowCount = this->output_table->JSON_map[coordinate].size() <= 0
			? 1 : this->output_table->JSON_map[coordinate].size();
		//取得した配列の値を末端まで走査してダイアログを作成する
		for (int i = 0; i < row; i++) {
			//先頭から順にテキストを入れていく
			this->Detailed_Dialog->Detailed[0,i]->Value = 
				this->output_table->Convert_String(this->output_table->JSON_map[coordinate][i], this->to_System);;
		}
		
		//ダイアログの表示
		this->Detailed_Dialog->ShowDialog();
	}
			 //基本ダイアログを開くイベント
	private: System::Void 基本ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		//基本ダイアログの生成
		this->basic = gcnew Basic();
		//ダイアログの表示
		this->basic->ShowDialog();
		//基本画面からオブジェクトを受け取りMyFormで使う
		this->output_table = this->basic->Json_Task;

		//表の縦の値をセット
		this->grid_table->RowCount = this->output_table->max_position_y();
		//表の横の値をセット
		this->grid_table->ColumnCount = this->output_table->max_position_x();

		//列の走査
		for (int j = 0; j < this->grid_table->RowCount; j++) {
			//行の走査
			for (int i = 0; i < this->grid_table->ColumnCount; i++) {
				//TextBox を新たに生成
				this->panel = gcnew TextBox();
				//TextBoxの大きさを決定
				this->panel->Size = System::Drawing::Size(100, 30);
				//セルのダブルクリックイベントを設定
				this->panel->DoubleClick += gcnew System::EventHandler(this, &MyForm::Panel_DoubleClick);
				//TextBoxに表示するテキストを作成する
				this->panel->Text = this->output_TextBox(i,j);
				//テーブルにTextBoxを追加
				this->grid_table->Controls->Add(this->panel, i, j);
			}
		}
		//表を生成する
		this->Grid_Tab->Controls->Add(this->grid_table);
	}

	//TextBoxに表示するテキストをオブジェクトから取り出す
	String^ output_TextBox(int x,int y) {
		//extBoxに表示するテキスト
		String^ output = "";
		//配列の要素数
		int max = this->output_table->JSON_map[this->output_table->create_coordinate(x, y)].size() - 1;

		if (max < 0) {

			return output;
		}

		if (this->output_table->JSON_map[this->output_table->create_coordinate(x, y)][max]
			== this->output_table->array_identi) {
			
			output = 
			this->output_table->Convert_String(
			this->output_table->JSON_map[this->output_table->create_coordinate(x, y)][max - 1], this->to_System);
		}
		else {

			output =
			this->output_table->Convert_String(
				this->output_table->JSON_map[this->output_table->create_coordinate(x, y)][max], this->to_System);
		}


		return output;
	}
};
}
