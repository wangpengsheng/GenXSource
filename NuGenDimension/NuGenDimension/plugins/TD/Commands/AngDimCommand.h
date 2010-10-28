#ifndef __ANG_DIM_Command__
#define __ANG_DIM_Command__


#include "..//LinearDimDlg.h"
#include "..//TextParamsDlg.h"

class AngDimCommand : public ICommander, public IContextMenuInterface
{
	IApplicationInterface* m_app;
private:
	IGetPointPanel*        m_get_first_point_panel;
	IGetPointPanel*        m_get_second_point_panel;
	IGetPointPanel*        m_get_third_point_panel;
	IGetPointPanel*        m_get_fourth_point_panel;
	IGetPointPanel*        m_get_last_point_panel;

	IComboPanel*           m_precision_combo;
	CLinearDimDlg*         m_props_panel;
	IComboPanel*           m_text_align_panel;
	CTextParamsDlg*        m_text_params_panel;


	int                    m_step;

	CString m_message;

	SG_POINT               m_cur_pnt;
	SG_POINT               m_first_pnt;
	SG_POINT               m_second_pnt;
	SG_POINT               m_third_pnt;
	SG_POINT               m_fourth_pnt;

	SG_DIMENSION_STYLE        m_dim_style;

	CString                m_text;

	void                   NewScenar();
public:
	AngDimCommand(IApplicationInterface* appI);
	virtual ~AngDimCommand();

	virtual void            Start()	;
	virtual bool            PreTranslateMessage(MSG* pMsg);
	virtual void            Draw();
	IContextMenuInterface*    GetContextMenuInterface() {return this;};

	virtual void            SendCommanderMessage(COMMANDER_MESSAGE, void*);

private:	
	virtual unsigned int    GetItemsCount();
	virtual void            GetItem(unsigned int, CString&);
	virtual void            GetItemState(unsigned int, bool&, bool&);
	virtual HBITMAP  GetItemBitmap(unsigned int);
	virtual void            Run(unsigned int);

	void            MouseMove(unsigned int,int,int);
	void            LeftClick(unsigned int,int,int);
	void            OnEnter();
};

#endif