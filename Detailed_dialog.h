#pragma once

namespace Make_Application {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Detailed_dialog の概要
	/// </summary>
	public ref class Detailed_dialog : public System::Windows::Forms::Form
	{
	public:
		Detailed_dialog(void)
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
		~Detailed_dialog()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^  Detailed;
	protected:
	private: System::Windows::Forms::Button^  OK;

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
			this->Detailed = (gcnew System::Windows::Forms::DataGridView());
			this->OK = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Detailed))->BeginInit();
			this->SuspendLayout();
			// 
			// Detailed
			// 
			this->Detailed->BackgroundColor = System::Drawing::Color::GhostWhite;
			this->Detailed->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Detailed->GridColor = System::Drawing::SystemColors::ControlLightLight;
			this->Detailed->Location = System::Drawing::Point(25, 12);
			this->Detailed->Name = L"Detailed";
			this->Detailed->RowTemplate->Height = 21;
			this->Detailed->Size = System::Drawing::Size(270, 279);
			this->Detailed->TabIndex = 0;
			// 
			// OK
			// 
			this->OK->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->OK->Location = System::Drawing::Point(100, 302);
			this->OK->Name = L"OK";
			this->OK->Size = System::Drawing::Size(75, 23);
			this->OK->TabIndex = 1;
			this->OK->Text = L"OK";
			this->OK->UseVisualStyleBackColor = true;
			// 
			// Detailed_dialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(287, 337);
			this->Controls->Add(this->OK);
			this->Controls->Add(this->Detailed);
			this->Name = L"Detailed_dialog";
			this->Text = L"Detailed_dialog";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Detailed))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	};
}
