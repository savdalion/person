#pragma once

#include <string>


namespace smik {


/**
* ������� ������������ ������ ������ ��������.
* LOW_LEVEL - ������������ ������� �������������, ������� � �������� �������
* ������������ �� ������� (��. ����� ��� ����� ��������).
*
* (!) ����� ������� ������ ���� �������.
*/
//#define IZO_118x118_LOW_LEVEL_SMIK_VISUALTEST
//#define IZO_94x94_LOW_LEVEL_SMIK_VISUALTEST
//#define IZO_82x82_LOW_LEVEL_SMIK_VISUALTEST
//#define BLOCK_MATTER_IZO_SMIK_VISUALTEST
//#define MAP_BLOCK_MATTER_IZO_SMIK_VISUALTEST
#define MAP_BLOCK_MATTER_PHYSICS_SMIK_VISUALTEST


/**
* ��������� ������� ����� ������������ �������������� ��������� ���
* ���������� �����������.
*/
#define SAVE_WORLD_INTO_STORE_IZO_SMIK_VISUALTEST



/**
* ����� ��� ������� � CouchDB.
* �������� ��������� ������ � CouchDB.
* ��� ������������ � ������ ��� �������� ���������.
*/
const std::string URL_COUCHDB_STORE = "http://127.0.0.1:5984";
const std::string NAME_COUCHDB_STORE = "montevey-t";
const std::string USER_COUCHDB_STORE = "";
const std::string PASSWORD_COUCHDB_STORE = "";



/**
* ������������ �����������.
* ������ ���� �������, ��� Entity, �� ���� �������� -
* ��. ����. � IzoOgre3DVisual::operator<<( IzoPicture ).
*/
//#define BILLBOARD_VISUALIZER_SMIK



/**
* ���� � ������ � �������� �������.
*/
const std::string PATH_MEDIA = "D:/Projects/workspace/smik/smik-visualtest/data/element-example/94x94/";



} // smik
