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
	/// MyForm �̊T�v
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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
	private: System::Windows::Forms::ToolStripMenuItem^  ��{ToolStripMenuItem;
	private: System::Windows::Forms::TabControl^  Tab_Select;
	private: System::Windows::Forms::TabPage^  Grid_Tab;



	private: System::Windows::Forms::TabPage^  List_Tab;

	private: System::Windows::Forms::Button^  �L�����Z��;

	private: System::Windows::Forms::Button^  �쐬;

	private: System::Windows::Forms::Button^  OK;
	private: System::Windows::Forms::TextBox^  ��BOX;

	private: System::Windows::Forms::TextBox^  �cBOX;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  ���RBOX;

	private: System::Windows::Forms::TextBox^  �^�eBOX;
	private: System::Windows::Forms::Label^  ���R;


	private: System::Windows::Forms::Label^  �^�e;
	private: System::Windows::Forms::TableLayoutPanel^  grid_table;

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->��{ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Tab_Select = (gcnew System::Windows::Forms::TabControl());
			this->Grid_Tab = (gcnew System::Windows::Forms::TabPage());
			this->�L�����Z�� = (gcnew System::Windows::Forms::Button());
			this->�쐬 = (gcnew System::Windows::Forms::Button());
			this->OK = (gcnew System::Windows::Forms::Button());
			this->��BOX = (gcnew System::Windows::Forms::TextBox());
			this->�cBOX = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->List_Tab = (gcnew System::Windows::Forms::TabPage());
			this->���RBOX = (gcnew System::Windows::Forms::TextBox());
			this->�^�eBOX = (gcnew System::Windows::Forms::TextBox());
			this->���R = (gcnew System::Windows::Forms::Label());
			this->�^�e = (gcnew System::Windows::Forms::Label());
			this->grid_table = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->menuStrip1->SuspendLayout();
			this->Tab_Select->SuspendLayout();
			this->Grid_Tab->SuspendLayout();
			this->List_Tab->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->��{ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(860, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ��{ToolStripMenuItem
			// 
			this->��{ToolStripMenuItem->Name = L"��{ToolStripMenuItem";
			this->��{ToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->��{ToolStripMenuItem->Text = L"��{";
			this->��{ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��{ToolStripMenuItem_Click);
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
			this->Grid_Tab->Controls->Add(this->�L�����Z��);
			this->Grid_Tab->Controls->Add(this->�쐬);
			this->Grid_Tab->Controls->Add(this->OK);
			this->Grid_Tab->Controls->Add(this->��BOX);
			this->Grid_Tab->Controls->Add(this->�cBOX);
			this->Grid_Tab->Controls->Add(this->label2);
			this->Grid_Tab->Controls->Add(this->label1);
			this->Grid_Tab->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Grid_Tab->Location = System::Drawing::Point(4, 22);
			this->Grid_Tab->Name = L"Grid_Tab";
			this->Grid_Tab->Padding = System::Windows::Forms::Padding(3);
			this->Grid_Tab->Size = System::Drawing::Size(828, 422);
			this->Grid_Tab->TabIndex = 0;
			this->Grid_Tab->Text = L"�O���b�h";
			this->Grid_Tab->UseVisualStyleBackColor = true;
			// 
			// �L�����Z��
			// 
			this->�L�����Z��->Location = System::Drawing::Point(703, 19);
			this->�L�����Z��->Name = L"�L�����Z��";
			this->�L�����Z��->Size = System::Drawing::Size(75, 23);
			this->�L�����Z��->TabIndex = 6;
			this->�L�����Z��->Text = L"�L�����Z��";
			this->�L�����Z��->UseVisualStyleBackColor = true;
			// 
			// �쐬
			// 
			this->�쐬->Location = System::Drawing::Point(597, 19);
			this->�쐬->Name = L"�쐬";
			this->�쐬->Size = System::Drawing::Size(75, 23);
			this->�쐬->TabIndex = 5;
			this->�쐬->Text = L"�쐬";
			this->�쐬->UseVisualStyleBackColor = true;
			this->�쐬->Click += gcnew System::EventHandler(this, &MyForm::�쐬_Click);
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
			// ��BOX
			// 
			this->��BOX->Location = System::Drawing::Point(36, 27);
			this->��BOX->Name = L"��BOX";
			this->��BOX->Size = System::Drawing::Size(100, 19);
			this->��BOX->TabIndex = 3;
			// 
			// �cBOX
			// 
			this->�cBOX->Location = System::Drawing::Point(36, 6);
			this->�cBOX->Name = L"�cBOX";
			this->�cBOX->Size = System::Drawing::Size(100, 19);
			this->�cBOX->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"���R";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�^�e";
			// 
			// List_Tab
			// 
			this->List_Tab->Controls->Add(this->���RBOX);
			this->List_Tab->Controls->Add(this->�^�eBOX);
			this->List_Tab->Controls->Add(this->���R);
			this->List_Tab->Controls->Add(this->�^�e);
			this->List_Tab->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->List_Tab->Location = System::Drawing::Point(4, 22);
			this->List_Tab->Name = L"List_Tab";
			this->List_Tab->Padding = System::Windows::Forms::Padding(3);
			this->List_Tab->Size = System::Drawing::Size(828, 422);
			this->List_Tab->TabIndex = 1;
			this->List_Tab->Text = L"���X�g";
			this->List_Tab->UseVisualStyleBackColor = true;
			// 
			// ���RBOX
			// 
			this->���RBOX->Location = System::Drawing::Point(34, 27);
			this->���RBOX->Name = L"���RBOX";
			this->���RBOX->Size = System::Drawing::Size(100, 19);
			this->���RBOX->TabIndex = 7;
			// 
			// �^�eBOX
			// 
			this->�^�eBOX->Location = System::Drawing::Point(34, 6);
			this->�^�eBOX->Name = L"�^�eBOX";
			this->�^�eBOX->Size = System::Drawing::Size(100, 19);
			this->�^�eBOX->TabIndex = 6;
			// 
			// ���R
			// 
			this->���R->AutoSize = true;
			this->���R->Location = System::Drawing::Point(4, 30);
			this->���R->Name = L"���R";
			this->���R->Size = System::Drawing::Size(23, 12);
			this->���R->TabIndex = 5;
			this->���R->Text = L"���R";
			// 
			// �^�e
			// 
			this->�^�e->AutoSize = true;
			this->�^�e->Location = System::Drawing::Point(4, 9);
			this->�^�e->Name = L"�^�e";
			this->�^�e->Size = System::Drawing::Size(24, 12);
			this->�^�e->TabIndex = 4;
			this->�^�e->Text = L"�^�e";
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
		//�c�̐��l��ۊǂ���ϐ�
		int Vertical = 0;
		//���̐��l��ۊǂ���ϐ�
		int Side = 0;
		//�G���R�[�f�B���O std::string -> SystemStrig^�p
		System::Text::Encoding^ to_System = System::Text::Encoding::GetEncoding(65001);
		//�G���R�[�f�B���O SystemStrig^ -> std::string�p
		System::Text::Encoding^ to_std = System::Text::Encoding::GetEncoding(0);
		//���I�ɐ�������e�L�X�gBOX
		System::Windows::Forms::TextBox^  panel;
		//��{�_�C�A���O���J���I�u�W�F�N�g
		ref class Basic^ basic;
		//�ڍ׃_�C�A���O���J���I�u�W�F�N�g
		ref class Detailed_dialog^ Detailed_Dialog;
		//JSON�������s�����߂̃N���X�I�u�W�F�N�g
		JSON_Task* output_table;

		//�\���쐬��JSON�̒l��z�u����
	   //OK�{�^�����N���b�N�����Ƃ��ɏc���̒l��ǂݎ��table��column row �Ɋ��蓖�Ă�
	private: System::Void OK_Click(System::Object^  sender, System::EventArgs^  e) {

		//�������܂܂�Ă����� Int�^�ŕ\���ł��Ȃ����l�̏ꍇ��O���������邽�� try catch �ň͂�
		try {
			//�c�̐��l������int�^�����ɕϊ�
			this->Vertical = Convert::ToInt32(this->�cBOX->Text);
			//���̐��l������int�^�����ɕϊ�
			this->Side = Convert::ToInt32(this->��BOX->Text);

			//�c���̒l���傫������ƃI�[�o�[�t���[���邽��
			if (400 <= this->Vertical * this->Side) {
				//�x����
				MessageBox::Show("�\��\��������܂���");
				return;
			}

			//���ۂɕ\�̉��̒��������߂�
			this->grid_table->ColumnCount = this->Side;
			//���ۂɕ\�̏c�̒��������߂�
			this->grid_table->RowCount = this->Vertical;
			//�ݒ肵�����e��\��
			MessageBox::Show("�c" + this->Vertical + "��\n" + "��" + this->Side + "�s�Őݒ肵�܂�");
		}
		//�������܂܂�Ă���ꍇ ��O���L���b�`
		catch (FormatException^ ex) {
			//�G���[���b�Z�[�W
			MessageBox::Show("���l����͂��Ă�������");
			return;
		}
	}
			 //���ۂɕ\���쐬
	private: System::Void �쐬_Click(System::Object^  sender, System::EventArgs^  e) {

		//�e�L�X�g�{�b�N�X�ɏc���̐�������͂��Ă��邩���ׂ�
		if (this->Vertical == 0 || this->Side == 0) {
			//�x����
			MessageBox::Show("�z��̗v�f�������߂Ă�������");
			return;
		}
		//�\�̏c�̒l���Z�b�g
		this->grid_table->RowCount = this->Vertical;
		//�\�̉��̒l���Z�b�g
		this->grid_table->ColumnCount = this->Side;

		//��̑���
		for (int j = 0; j < this->grid_table->RowCount; j++) {
			//�s�̑���
			for (int i = 0; i < this->grid_table->ColumnCount; i++) {
				//TextBox ��V���ɐ���
				this->panel = gcnew TextBox();
				//TextBox�̑傫��������
				this->panel->Size = System::Drawing::Size(100, 30);
				//�Z���̃_�u���N���b�N�C�x���g��ݒ�
				this->panel->DoubleClick += gcnew System::EventHandler(this, &MyForm::Panel_DoubleClick);
				//�e�[�u����TextBox��ǉ�
				this->grid_table->Controls->Add(this->panel, i, j);
			}
		}
		//�\�𐶐�����
		this->Grid_Tab->Controls->Add(this->grid_table);
	}
	//�e�R���g���[�����N���b�N�����Ƃ��̃C�x���g
	//�_�C�A���O��\����JSON�̏ڍׂ�\�����A
	//OK�{�^�������Ń����o��map��ύX����
	private: System::Void Panel_DoubleClick(System::Object^  sender, System::EventArgs^  e) {

		//���W�擾
		int y_p = this->grid_table->GetCellPosition((TextBox^)sender).Row;
		int x_p = this->grid_table->GetCellPosition((TextBox^)sender).Column;
		//key���ƂȂ���W�������擾
		std::string coordinate = this->output_table->create_coordinate(x_p, y_p);
		//�_�u���N���b�N�����ꏊ�̔z��̗v�f��
		int row = this->output_table->JSON_map[coordinate].size();

		//�z��𖖒[�܂ő������ĕ������\�ɂ���
		for (auto itr = this->output_table->JSON_map[coordinate].begin();
			itr != this->output_table->JSON_map[coordinate].end(); itr++) {

		}

		//�ڍ׃_�C�A���O�̐���
		this->Detailed_Dialog = gcnew Detailed_dialog();
		//���̕\���쐬����
		this->Detailed_Dialog->Detailed->ColumnCount = 1;
		//�Œ�ł� 1 �ȏ�ݒ肷��
		this->Detailed_Dialog->Detailed->RowCount = this->output_table->JSON_map[coordinate].size() <= 0
			? 1 : this->output_table->JSON_map[coordinate].size();
		//�擾�����z��̒l�𖖒[�܂ő������ă_�C�A���O���쐬����
		for (int i = 0; i < row; i++) {
			//�擪���珇�Ƀe�L�X�g�����Ă���
			this->Detailed_Dialog->Detailed[0,i]->Value = 
				this->output_table->Convert_String(this->output_table->JSON_map[coordinate][i], this->to_System);;
		}
		
		//�_�C�A���O�̕\��
		this->Detailed_Dialog->ShowDialog();
	}
			 //��{�_�C�A���O���J���C�x���g
	private: System::Void ��{ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		//��{�_�C�A���O�̐���
		this->basic = gcnew Basic();
		//�_�C�A���O�̕\��
		this->basic->ShowDialog();
		//��{��ʂ���I�u�W�F�N�g���󂯎��MyForm�Ŏg��
		this->output_table = this->basic->Json_Task;

		//�\�̏c�̒l���Z�b�g
		this->grid_table->RowCount = this->output_table->max_position_y();
		//�\�̉��̒l���Z�b�g
		this->grid_table->ColumnCount = this->output_table->max_position_x();

		//��̑���
		for (int j = 0; j < this->grid_table->RowCount; j++) {
			//�s�̑���
			for (int i = 0; i < this->grid_table->ColumnCount; i++) {
				//TextBox ��V���ɐ���
				this->panel = gcnew TextBox();
				//TextBox�̑傫��������
				this->panel->Size = System::Drawing::Size(100, 30);
				//�Z���̃_�u���N���b�N�C�x���g��ݒ�
				this->panel->DoubleClick += gcnew System::EventHandler(this, &MyForm::Panel_DoubleClick);
				//TextBox�ɕ\������e�L�X�g���쐬����
				this->panel->Text = this->output_TextBox(i,j);
				//�e�[�u����TextBox��ǉ�
				this->grid_table->Controls->Add(this->panel, i, j);
			}
		}
		//�\�𐶐�����
		this->Grid_Tab->Controls->Add(this->grid_table);
	}

	//TextBox�ɕ\������e�L�X�g���I�u�W�F�N�g������o��
	String^ output_TextBox(int x,int y) {
		//extBox�ɕ\������e�L�X�g
		String^ output = "";
		//�z��̗v�f��
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
