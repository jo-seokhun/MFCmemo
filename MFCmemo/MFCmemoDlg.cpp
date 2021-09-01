
// MFCmemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCmemo.h"
#include "MFCmemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCmemoDlg 대화 상자



CMFCmemoDlg::CMFCmemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCMEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCmemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_TB_MEMO1, strMemo);
	DDX_Control(pDX, IDC_TB_MEMO2, CMemo2);
	DDX_Control(pDX, IDC_TB_MEMO1, CMemo1);
	DDX_Control(pDX, IDC_CHB_1, CHB1);
	DDX_Control(pDX, IDC_RB1, RB1);
	DDX_Control(pDX, IDC_RB2, RB2);
}

BEGIN_MESSAGE_MAP(CMFCmemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TEST, &CMFCmemoDlg::OnClickedBtnTest)
	
	ON_COMMAND(IDC_RB1, &CMFCmemoDlg::OnRb1)
	ON_BN_CLICKED(IDC_RB1, &CMFCmemoDlg::OnBnClickedRb1)
	ON_BN_CLICKED(IDC_BTN_2, &CMFCmemoDlg::OnClickedBtn2)
	ON_COMMAND(ID_MNU_VIEW_LOWER, &CMFCmemoDlg::OnMnuViewLower)
	ON_COMMAND(ID_MNU_VIEW_UPPER, &CMFCmemoDlg::OnMnuViewUpper)
	ON_COMMAND(ID_MNU_VIEW_HEX, &CMFCmemoDlg::OnMnuViewHex)
	ON_BN_CLICKED(IDOK, &CMFCmemoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCmemoDlg::OnBnClickedCancel)
	ON_COMMAND(ID_MNU_EXIT, &CMFCmemoDlg::OnMnuExit)
END_MESSAGE_MAP()


// CMFCmemoDlg 메시지 처리기

BOOL CMFCmemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_MINIMIZE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCmemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCmemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCmemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//EditBox에 입력된 텍스트 중 모든 소문자를 대문자로 변환
int count = 0; //static variable
void CMFCmemoDlg::OnClickedBtnTest()
{
	CString cstr, s1;
	CString cs,cs1;
	char buf[1024] ;
	char* sp = buf;
	char *str = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0 ; *(str + i); i++)  //i<strlen(str)
	{
		//char 배열 및 포인터를 이용 
		sprintf(sp,"%02X ", str[i]);
		while (*sp) sp++;

		//CString class 이용
		cs1.Format("%02X ", str[i]);
		cs += cs1;		//문자를 문자열의 끝부분에 연결한다.
	}
	CMemo2.SetWindowTextA(buf);
	CMemo2.SetWindowTextA(cs+buf);

	/*
	char buf[1024];
	//char *str = strMemo.GetBuffer();
	
	int len=CMemo1.GetWindowTextA(buf,1024);
	
//	if (count % 2==1) //2로 나누었을 때 나머지가 있다 즉 홀수인경우
//	{
//		for (int i = 0; i < k; i++)
//		{
//			if (buf[i] >= 'a' && buf[i] <= 'z') buf[i] -= 0x20; // 대문자로
//		}
//	}
//	else    //짝수인 경우
//	{
//		for (int i = 0; i < k; i++)
//		{
//			if (buf[i] >= 'A' && buf[i] <= 'Z') buf[i] += 0x20;
//		}
//	}
	

	CString cstr,s1;
	//int word;
	CMemo1.GetWindowTextA(cstr);


	//word=cstr.GetLength();


	//getstate()는 뭐지;체크가 되어있으면 true 안되어있으면 false 값을 가져옴
	//if (count % 2 == 1) s1=cstr.MakeLower();
	if (((CButton*)GetDlgItem(IDC_CHB_1))->GetState()==true)s1 = cstr.MakeUpper();
	else if (((CButton*)GetDlgItem(IDC_CHB_2))->GetState() == true) s1=cstr.MakeLower();
	else if (((CButton*)GetDlgItem(IDC_RB2))->GetState() == true) s1 = cstr.MakeLower();
	else if (((CButton*)GetDlgItem(IDC_RB1))->GetState() == true) s1 = cstr.MakeUpper();
	CMemo2.SetWindowTextA(s1);
	//if ((CButton*)GetDlgItem(IDC_BTN_2)->GetState() == true) SetDlgItemInt(IDC_BTN_2,word);
	count++;
	*/
}

void CMFCmemoDlg::OnMnuViewLower()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString cstr;
	CMemo1.GetWindowTextA(cstr);
	CMemo2.SetWindowTextA(cstr.MakeLower());
}


void CMFCmemoDlg::OnMnuViewUpper()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString cstr, s1;
	CMemo1.GetWindowTextA(cstr);
	s1 = cstr.MakeUpper();
	CMemo2.SetWindowTextA(s1);
}


void CMFCmemoDlg::OnMnuViewHex()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
}

void CMFCmemoDlg::OnClickedChb1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCmemoDlg::OnRb1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCmemoDlg::OnBnClickedRb1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCmemoDlg::OnClickedBtn2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}





void CMFCmemoDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CMFCmemoDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CMFCmemoDlg::OnMnuExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	EndDialog(0);
}
