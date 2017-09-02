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

private :
	//JSON�p�[�T�Ńc���[�\���ɂ����I�u�W�F�N�g�𑀍삷�邽�߂̃I�u�W�F�N�g
	std::map<std::string, std::vector<std::string>> JSON_map;
	//�f�t�H���g�R���X�g���X�^
	JSON_Task();
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