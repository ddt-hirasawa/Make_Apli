#pragma once
#include <map>
#include <vector>
#include <string>

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

	/*
	�֐��� : output_array
	�T�v   : �R���g���[���̍��W������key�Ƃ��Ĕz������o��
	����   : �R���g���[���̍��W����
	�ԋp�l : map�ɓ����Ă���z��
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/

	/*
	�֐��� : put_map
	�T�v   : key���Ɣz����w�肵��map�ɉ�����
	����   : std::string �R���g���[���̍��W����,std::vector<std::string> vec������z��
	�ԋp�l : ����
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/

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

	/*
	�֐��� : init
	�T�v   : �f�[�^������������
	����   : ����
	�ԋp�l : ����
	�쐬�� : 2017�N9��2��
	�쐬�� : ���V�h��
	*/
};