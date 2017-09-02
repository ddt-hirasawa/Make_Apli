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
�N���X�� JSON_Task 
�T�v : JSON�p�[�T�Ńc���[�\���ɂ�������������o���܂��B�����\�ɂ��邽�߂�key�����R���g���[���̍��W�Ƃ���
map�ɕϊ����邽�߂̃N���X
�R���g���[���̍��W (x,y) -> std;;string ���W = "x.y"; �Ƃ���C���[�W
�쐬�� : 2017�N9��2��
�쐬�� : ���V�h��
*/
class JSON_Task {

public :
	//JSON�p�[�T�Ńc���[�\���ɂ����I�u�W�F�N�g�𑀍삷�邽�߂̃I�u�W�F�N�g
	std::map<std::string, std::vector<std::string>> JSON_map;
	//�R���g���[���̍��W����
	std::string coordinate = "";
	//�R���g���[���̍��W�������쐬����ϐ� x y
	int x_position = 0;
	int y_position = 0;
	//�R���g���[���̍��W�̍ő�l
	int max_x_position = 0;
	int max_y_position = 0;
	//�z��v�f�̎��ʂ�
	std::string array_identi = "This_is_an_array_element";
	//�f�t�H���g�R���X�g���X�^
	JSON_Task() {};
	//�R���X�g���X�^ �쐬����map�������o�ɉ�����
	JSON_Task(std::map<std::string, std::vector<std::string>> map)
		: JSON_map(map) {};

	/*
	�֐��� : JSON_map
	�T�v   : �c���[�\���̃f�[�^����R���g���[���̍��W����key�Ƃ���map���쐬����쐬����֐�
	����   : ptree pt �c���[�\���̃f�[�^, std::vector<std::string> tmp ���Z����z��
	�ԋp�l : ����
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	void create_map(ptree pt, std::vector<std::string> tmp) {

		//�z��̗v�f���𒲂ׂ�J�E���^
		int count = 0;
		//�z��v�f�����p�̃c���[�\���I�u�W�F�N�g
		ptree array_pt;

		//�C�e���[�^���g�������܂ő�������
		BOOST_FOREACH(const boost::property_tree::ptree::value_type& e, pt) {

			//�z��\���̔��莮 �z��̏ꍇ value �̃L�[������ɂȂ��Ă���͂�
			if (e.first.empty()) {

				//�I�u�W�F�N�g�\���Ȃ̂�����
				if (0 < e.second.size()) {
					//�I�u�W�F�N�g�̏ꍇ�C�e���[�^�ő��삵�ăL�[���ƒl������
					BOOST_FOREACH(const boost::property_tree::ptree::value_type& array_object, e.second) {
						//key��������
						tmp.push_back(array_object.first);
						//�l������
						tmp.push_back(array_object.second.data());
					}
					//�z��̎��ʗp�̕���������
					tmp.push_back(this->array_identi);
					//value �v�f������
				}
				else {
					//�l������
					tmp.push_back(e.second.data());
					//�z��̎��ʗp�̕���������
					tmp.push_back(this->array_identi);
				}

				//���W�������쐬
				this->coordinate = this->create_coordinate(this->x_position, y_position);
				//���ۂ�map�ɒǉ�
				this->JSON_map[this->coordinate] = tmp;

				//�I�u�W�F�N�g�\���Ȃ̂�����
				if (0 < e.second.size()) {
					//���̗v�f�ɔ����ĕs�v�Ȓl�����o��
					tmp.pop_back();
					tmp.pop_back();
					tmp.pop_back();

					//value �v�f������
				}
				else {
					//���̗v�f�ɔ����ĕs�v�Ȓl�����o��
					tmp.pop_back();
					tmp.pop_back();
				}
				//x���W���X�V
				this->x_position++;

			//�I�u�W�F�N�g�\���̔��莮 �I�u�W�F�N�g�̏ꍇ second�̗v�f��size ��1�ȏ�ɂȂ��Ă���͂�
			} else if (0 < e.second.size()) {

				//�z��ɃL�[����ǉ�����
				tmp.push_back(e.first);
				//�ċA�������s��
				create_map(e.second, tmp);
				//�L�[�������o��
				tmp.pop_back();
				//�ő�l���X�V����
				if (max_x_position < x_position) {
					this->max_x_position = x_position;
				}
				//���W���X�V
				this->x_position = 0;
				this->y_position++;
				//y���̍ő�l���X�V
				this->max_y_position = this->y_position;
				//����ȊO�̏ꍇ value�v�f�̂͂�
			}
			else {
				//key��������
				tmp.push_back(e.first);
				//�l������
				tmp.push_back(e.second.data());

				//���W�������쐬
				this->coordinate = this->create_coordinate(this->x_position,y_position);
				//���ۂ�map�ɒǉ�
				this->JSON_map[this->coordinate] = tmp;
				//���̗v�f�ɔ����Ēl�����o��
				tmp.pop_back();
				tmp.pop_back();
				//x���W���X�V����
				this->x_position++;
			}
		}
	}
	/*
	�֐��� : create_coordinate
	�T�v   : �R���g���[���̍��W�������쐬����
	����   : int x,y �R���g���[���̍��W
	�ԋp�l : std::string ���W����
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	std::string create_coordinate(int x, int y) {
		//���W������ԋp ->  x.y �̌`
		return boost::lexical_cast<std::string>(x) + "." + boost::lexical_cast<std::string>(y);
	}
	/*
	�֐��� : max_position_x
	�T�v   : x���̍ő�l��Ԃ�
	����   : ����
	�ԋp�l : x���̍ő�l
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	int max_position_x() const {

		return this->max_x_position;
	}
	/*
	�֐���: max_position_y
	�T�v : y���̍ő�l��Ԃ�
	���� : ����
	�ԋp�l : y���̍ő�l
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	int max_position_y() const {

		return this->max_y_position;
	}

	/*
	�֐��� : init_X_Y
	�T�v   : �R���g���[���̍��W����������������
	����   : ����
	�ԋp�l : ����
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	void init_X_Y() {
		//���W��(0,0)�ɐݒ�
		this->x_position = 0;
		this->y_position = 0;
	}

	/*
	�֐��� : output_array
	�T�v   : �R���g���[���̍��W������key�Ƃ��Ĕz������o��
	����   : �R���g���[���̍��W����
	�ԋp�l : map�ɓ����Ă���z��
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	std::vector<std::string> output_array(std::string coordinate) {
		
		return this->JSON_map[coordinate];
	}
	/*
	�֐��� : put_map
	�T�v   : key���Ɣz����w�肵��map�ɉ�����
	����   : std::string �R���g���[���̍��W����,std::vector<std::string> vec������z��
	�ԋp�l : ����
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	void put_map(std::string coordinate, std::vector<std::string> vec) {

		this->JSON_map[coordinate] = vec;
	}
	/*
	�֐��� : Convert_String
	�T�v   : std::string ������� System::String^������ɕ����R�[�h���w�肵�ĕϊ�����
	����   : std::string ������ System::Text::Encoding^ �G���R�[�f�B���O
	�Q��   : http://d.hatena.ne.jp/It_lives_vainly/20070824/1187947992
	�ԋp�l : System::String^������
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	String^ Convert_String(const std::string& i_src,System::Text::Encoding^ i_encoding) {
		//�G���R�[�f�B���O���w�肵�ĐV����String^�^�̕�����𐶐�����
		return  gcnew System::String(i_src.data(), 0, i_src.size(), i_encoding);
	}
	/*
	�֐��� : Convert_string
	�T�v   : System::String ������� std::string ������ɕ����R�[�h���w�肵�ĕϊ�����
	����   : System::String ������ System::Text::Encoding^ �G���R�[�f�B���O
	�Q��   : http://d.hatena.ne.jp/It_lives_vainly/20070824/1187947992
	�ԋp�l : std::string ������
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	std::string Convert_string(System::String^ i_src, System::Text::Encoding^ i_encoding) {
		//�ϊ������������⊮����ϐ�
		std::string a_str;

		//���莮
		if (i_src != nullptr &&  i_src->Length > 0) {
			//�ϊ����邽�߂Ɉꎞ�I��byte �ŕۊǂ���
			array< Byte >^ a_array = System::Text::Encoding::Convert(
				System::Text::Encoding::Unicode,		// �ϊ����G���R�[�f�B���O
				i_encoding,								// �ϊ���G���R�[�f�B���O
				System::Text::Encoding::Unicode->GetBytes(i_src));
			//
			pin_ptr<Byte> a_pin = &a_array[0];
			a_str.assign(reinterpret_cast<char*>(a_pin), a_array->Length);
		}
		//String^ ���� std::string �ɕϊ� 
		return a_str;
	}
	/*
	�֐��� : erace_map
	�T�v   : key�����w�肵��map�����菜��
	����   : std::string �R���g���[���̍��W����
	�ԋp�l : ����
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	void erace_map(std::string coordinate) {
		//�C�e���[�^�ňʒu����肷��
		auto itr = this->JSON_map.find(coordinate);
		//key���̒l�������Ă��邩�m�F����
		if (itr != this->JSON_map.end()) {
			//�����Ă���Ȃ�΍폜����
			this->JSON_map.erase(itr);
		}
		else {
			//�G���[���b�Z�[�W��\������
			MessageBox::Show("�폜�ł��܂���ł���");
		}
	}
	/*
	�֐��� : init
	�T�v   : �f�[�^������������
	����   : ����
	�ԋp�l : ����
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
	void init() {
		//map��������
		this->JSON_map.erase(this->JSON_map.begin(),this->JSON_map.end());
	}
};
}