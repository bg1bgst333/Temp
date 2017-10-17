// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <cstring>	// C�����񏈗�.
#include <wchar.h>	// ���C�h����.
// �Ǝ��̃w�b�_
#include "TextFile.h"	// CTextFile

// �R���X�g���N�^CTextFile
CTextFile::CTextFile() : CBinaryFile(){

	// �����o�̏�����
	m_ptszText = NULL;	// m_ptszText��NULL���Z�b�g.
	m_dwLen = 0;	// m_dwLen��0���Z�b�g.

}

// �f�X�g���N�^CTextFile
CTextFile::~CTextFile() {

	// �t�@�C���ƃo�b�t�@���N���A����.
	Close();	// �t�@�C�������.
	Clear();	// �o�b�t�@��j��.

}

// �����o�֐�Read
BOOL CTextFile::Read(LPCTSTR lpctszFileName) {

	// �w�肳�ꂽ�t�@�C�����̃t�@�C����ǂݍ���.
	if (CBinaryFile::Read(lpctszFileName)) {	// �ǂݍ��݂ɐ���������.

		// �����R�[�h����.
		if (m_dwSize >= 2 && m_pBytes[0] == 0xff && m_pBytes[1] == 0xfe) {	// UTF-16LE�̏ꍇ.
			
			// �e�L�X�g�z��̐���.
			m_ptszText = new TCHAR[m_dwSize - 2 + 1];	// (�o�C�g�� - 2 + 1)����TCHAR�z�񂪂���Ώ\�����Ǝv����.
			wmemset(m_ptszText, _T('\0'), m_dwSize - 2 + 1);	// wmemset��m_ptszText��0�Ŗ��߂�.
			memcpy(m_ptszText, m_pBytes + 2, m_dwSize - 2);	// memcpy��m_pBytes��3�o�C�g�ڂ���m_ptszText�ɃR�s�[.
			m_dwLen = _tcslen(m_ptszText);	// _tcslen�̒l��m_dwLen�Ɋi�[.

			// �ǂݍ��ݐ����Ȃ̂�TRUE.
			return TRUE;	// TRUE��Ԃ�.

		}

	}

	// �ǂݍ��ݎ��s�Ȃ̂�FALSE.
	return FALSE;	// FALSE��Ԃ�.

}

// �����o�֐�Clear
void CTextFile::Clear() {

	// �e�L�X�g�z��̉��.
	if (m_ptszText != NULL) {	// m_ptszText��NULL�łȂ���.
		delete[] m_ptszText;	// delete[]�ŉ��.
		m_ptszText = NULL;		// m_ptszText��NULL���Z�b�g.
	}
	m_dwLen = 0;	// m_dwLen��0���Z�b�g.

	// �o�C�i���f�[�^���N���A.
	CBinaryFile::Clear();	// CBinaryFile::Clear�ŃN���A.

}