
// MFCmemoDlg.h: 헤더 파일
//

#pragma once


// CMFCmemoDlg 대화 상자
class CMFCmemoDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCmemoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCMEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedBtnTest();
//	CString strMemo;
// TB_MEMO1의 입력 텍스트 내용   Cstring (MFC) -> string (표준 C++) 
	CEdit CMemo2; //얘는 컨트롤 타입으로 형식이 CEdit이다.
	CEdit CMemo1;
	CButton CHB1;
	afx_msg void OnClickedChb1();
	afx_msg void OnRb1();
	afx_msg void OnBnClickedRb1();
	CButton RB1;
	CButton RB2;
	afx_msg void OnClickedBtn2();
	afx_msg void OnMnuViewLower();
	afx_msg void OnMnuViewUpper();
	afx_msg void OnMnuViewHex();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnMnuExit();
};
