#include "stdafx.h"

#include "Cone.h"

#include "..//resource.h"

#include <math.h>

int     cone_name_index = 1;


ConeCommand::ConeCommand(IApplicationInterface* appI):
				m_app(appI)
				,m_get_first_point_panel(NULL)
				,m_get_second_point_panel(NULL)
				,m_get_r1_panel(NULL)
				,m_get_r2_panel(NULL)
				, m_step(0)
{
	ASSERT(m_app);
}

ConeCommand::~ConeCommand()
{
	m_app->GetCommandPanel()->RemoveAllDialogs();
	m_app->GetViewPort()->InvalidateViewPort();
}


bool    ConeCommand::PreTranslateMessage(MSG* pMsg)
{
	try {
		/*if (pMsg->message==WM_KEYUP||
		pMsg->message==WM_CHAR)
		return false;*/

		if (pMsg->message==WM_KEYUP||pMsg->message==WM_KEYDOWN || 
			pMsg->message==WM_CHAR)
		{
			if (pMsg->wParam==VK_RETURN)
			{
				OnEnter();
				return true;
			}
			if (pMsg->wParam==VK_ESCAPE)
			{
				m_app->StopCommander();
				return true;
			}
			switch(m_step) {
			case 0:
				if (m_get_first_point_panel)
					m_get_first_point_panel->GetWindow()->SendMessage(pMsg->message,
						pMsg->wParam,
						pMsg->lParam);
				break;
			case 1:
				if (m_get_second_point_panel)
					m_get_second_point_panel->GetWindow()->SendMessage(pMsg->message,
						pMsg->wParam,
						pMsg->lParam);
				break;
			case 2:
				if (m_get_r1_panel)
					m_get_r1_panel->GetWindow()->SendMessage(pMsg->message,
						pMsg->wParam,
						pMsg->lParam);
				break;
			case 3:
				if (m_get_r2_panel)
					m_get_r2_panel->GetWindow()->SendMessage(pMsg->message,
						pMsg->wParam,
						pMsg->lParam);
				break;
			default:
				return false;
			}
			if (pMsg->message==WM_KEYDOWN)
				return false;
			else 
				return true;
		}
		else
		{
			if (pMsg->hwnd == m_app->GetViewPort()->GetWindow()->m_hWnd)
			{
				switch(pMsg->message) 
				{
				case WM_MOUSEMOVE:
					MouseMove(pMsg->wParam,GET_X_LPARAM(pMsg->lParam),GET_Y_LPARAM(pMsg->lParam));
					return true;
				case WM_LBUTTONDOWN:
					LeftClick(pMsg->wParam,GET_X_LPARAM(pMsg->lParam),GET_Y_LPARAM(pMsg->lParam));
					return true;
				default:
					return false;
				}	
			}
		}
	}
	catch(...){
	}
	return false;
}


void   ConeCommand::SendCommanderMessage(ICommander::COMMANDER_MESSAGE mes, void* params)
{
	if (mes==ICommander::CM_SWITCH_ROLLUP_DIALOG)
	{
		ASSERT(params!=NULL);
		int   newActiveDlg = *(reinterpret_cast<int*>(params));

		ASSERT(newActiveDlg<=3);
		m_step = (unsigned int)newActiveDlg;
		for (unsigned int i=m_step+1;i<=3;i++)
			m_app->GetCommandPanel()->EnableRadio(i,false);
		SWITCH_RESOURCE
			switch(m_step) 
		{
			case 0:
				m_message.LoadString(IDS_CYL_ENTER_FIRST_P);
				break;
			case 1:
				m_message.LoadString(IDS_CYL_ENTER_SEC_P);
				break;
			case 2:
				m_message.LoadString(IDS_CONE_ENTER_FIR_RAD);
				break;
			case 3:
				m_message.LoadString(IDS_CONE_ENTER_SEC_RAD);
				break;
			default:
				ASSERT(0);
				break;
		}
		m_app->PutMessage(IApplicationInterface::MT_MESSAGE,m_message);
	}
}


void  ConeCommand::Start()	
{
	NewScenar();
	SWITCH_RESOURCE
	m_message.LoadString(IDS_TOOLTIP_THIRD);
	m_app->StartCommander(m_message);
}

void  ConeCommand::MouseMove(unsigned int nFlags,int pX,int pY)
{
	switch(m_step) 
	{
	case 0:
		{
			ASSERT(m_get_first_point_panel);
			IViewPort::GET_SNAP_IN in_arg;
			in_arg.scrX = pX;
			in_arg.scrY = pY;
			in_arg.snapType = SNAP_SYSTEM;
			in_arg.XFix = m_get_first_point_panel->IsXFixed();
			in_arg.YFix = m_get_first_point_panel->IsYFixed();
			in_arg.ZFix = m_get_first_point_panel->IsZFixed();
			double tmpFl[3];
			m_get_first_point_panel->GetPoint(tmpFl[0],tmpFl[1],tmpFl[2]);
			in_arg.FixPoint.x = tmpFl[0];
			in_arg.FixPoint.y = tmpFl[1];
			in_arg.FixPoint.z = tmpFl[2];
			IViewPort::GET_SNAP_OUT out_arg;
			m_app->GetViewPort()->GetWorldPointAfterSnap(in_arg,out_arg);
			m_cur_pnt = out_arg.result_point;
			m_get_first_point_panel->SetPoint(m_cur_pnt.x,m_cur_pnt.y,m_cur_pnt.z);
		}
		break;
	case 1:
		{
			ASSERT(m_get_second_point_panel);
			IViewPort::GET_SNAP_IN in_arg;
			in_arg.scrX = pX;
			in_arg.scrY = pY;
			in_arg.snapType = SNAP_SYSTEM;
			in_arg.XFix = m_get_second_point_panel->IsXFixed();
			in_arg.YFix = m_get_second_point_panel->IsYFixed();
			in_arg.ZFix = m_get_second_point_panel->IsZFixed();
			double tmpFl[3];
			m_get_second_point_panel->GetPoint(tmpFl[0],tmpFl[1],tmpFl[2]);
			in_arg.FixPoint.x = tmpFl[0];
			in_arg.FixPoint.y = tmpFl[1];
			in_arg.FixPoint.z = tmpFl[2];
			IViewPort::GET_SNAP_OUT out_arg;
			m_app->GetViewPort()->GetWorldPointAfterSnap(in_arg,out_arg);
			m_cur_pnt = out_arg.result_point;
			m_get_second_point_panel->SetPoint(m_cur_pnt.x,m_cur_pnt.y,m_cur_pnt.z);
		}
		break;
	case 2:
		{
			IViewPort::GET_SNAP_IN in_arg;
			in_arg.scrX = pX;
			in_arg.scrY = pY;
			in_arg.snapType = SNAP_SYSTEM;
			in_arg.XFix = in_arg.YFix = in_arg.ZFix = false;
			in_arg.FixPoint.x = in_arg.FixPoint.y = in_arg.FixPoint.z = 0.0;
			IViewPort::GET_SNAP_OUT out_arg;
			m_app->GetViewPort()->GetWorldPointAfterSnap(in_arg,out_arg);
			m_cur_pnt = out_arg.result_point;
			SG_POINT projection;
			m_rad_1 = sgSpaceMath::ProjectPointToLineAndGetDist(m_first_pnt,
				m_dir,
				m_cur_pnt,
				projection);
			m_rad_1 = m_app->ApplyPrecision(m_rad_1);
			ASSERT(m_get_r1_panel);
			m_get_r1_panel->SetNumber(m_rad_1);
		}
		break;
	case 3:
		{
			IViewPort::GET_SNAP_IN in_arg;
			in_arg.scrX = pX;
			in_arg.scrY = pY;
			in_arg.snapType = SNAP_SYSTEM;
			in_arg.XFix = in_arg.YFix = in_arg.ZFix = false;
			in_arg.FixPoint.x = in_arg.FixPoint.y = in_arg.FixPoint.z = 0.0;
			IViewPort::GET_SNAP_OUT out_arg;
			m_app->GetViewPort()->GetWorldPointAfterSnap(in_arg,out_arg);
			m_cur_pnt = out_arg.result_point;
			SG_POINT projection;
			m_rad_2= sgSpaceMath::ProjectPointToLineAndGetDist(m_second_pnt,
				m_dir,
				m_cur_pnt,
				projection);
			m_rad_2 = m_app->ApplyPrecision(m_rad_2);
			ASSERT(m_get_r2_panel);
			m_get_r2_panel->SetNumber(m_rad_2);
		}
		break;
	default:
		ASSERT(0);
	}
	m_app->GetViewPort()->InvalidateViewPort();
}

void  ConeCommand::LeftClick(unsigned int nFlags,int pX,int pY)
{
	SWITCH_RESOURCE
	switch(m_step) 
	{
	case 0:
		m_first_pnt=m_cur_pnt;
		m_step++;
		m_app->GetCommandPanel()->SetActiveRadio(m_step);
		m_message.LoadString(IDS_CYL_ENTER_SEC_P);
		m_app->PutMessage(IApplicationInterface::MT_MESSAGE,
			m_message);
		break;
	case 1:
		m_length = sgSpaceMath::PointsDistance(m_first_pnt,m_cur_pnt);
		if (m_length<0.0001)
		{
			m_message.LoadString(IDS_ERROR_ZERO_LENGTH);
			m_app->PutMessage(IApplicationInterface::MT_ERROR,
				m_message);
			return;
		}
		m_second_pnt=m_cur_pnt;
		m_dir.x = m_second_pnt.x-m_first_pnt.x;
		m_dir.y = m_second_pnt.y-m_first_pnt.y;
		m_dir.z = m_second_pnt.z-m_first_pnt.z;
		sgSpaceMath::NormalVector(m_dir);
		m_step++;
		m_app->GetCommandPanel()->SetActiveRadio(m_step);
		m_message.LoadString(IDS_CONE_ENTER_FIR_RAD);
		m_app->PutMessage(IApplicationInterface::MT_MESSAGE,
			m_message);
		break;
	case 2:
		{
			SG_POINT projection;
			double rd = sgSpaceMath::ProjectPointToLineAndGetDist(m_first_pnt,
				m_dir,
				m_cur_pnt,
				projection);
			rd = m_app->ApplyPrecision(rd);
			m_rad_1 = rd;
			m_step++;
			m_app->GetCommandPanel()->SetActiveRadio(m_step);
			m_message.LoadString(IDS_CONE_ENTER_SEC_RAD);
			m_app->PutMessage(IApplicationInterface::MT_MESSAGE,
				m_message);
		}
		break;
	case 3:
		{
			SG_POINT projection;
			double rd = sgSpaceMath::ProjectPointToLineAndGetDist(m_second_pnt,
				m_dir,
				m_cur_pnt,
				projection);
			rd = m_app->ApplyPrecision(rd);
			if (fabs(rd)<0.0001 && fabs(m_rad_1)<0.0001)
			{
				m_message.LoadString(IDS_ERROR_ZERO_BOTH_RADS);
				m_app->PutMessage(IApplicationInterface::MT_ERROR,
					m_message);
				return;
			}
			
			sgCCone* cone = sgCreateCone(fabs(m_rad_1),fabs(rd),fabs(m_length),24);
			if (!cone)
				return;

			cone->InitTempMatrix()->VectorToZAxe(m_dir);
			cone->GetTempMatrix()->Inverse();
			cone->GetTempMatrix()->Translate(m_first_pnt);
			cone->ApplyTempMatrix();
			cone->DestroyTempMatrix();

			CString nm;
			nm.LoadString(IDS_TOOLTIP_THIRD);
			CString nmInd;
			nmInd.Format("%i",cone_name_index);
			nm+=nmInd;
			cone->SetName(nm);
			
			sgGetScene()->StartUndoGroup();
			sgGetScene()->AttachObject(cone);
			m_app->ApplyAttributes(cone);
			sgGetScene()->EndUndoGroup();
			cone_name_index++;
			
			m_app->GetViewPort()->InvalidateViewPort();
			NewScenar();
		}
		break;
	default:
		ASSERT(0);
		break;
	}
}


void  ConeCommand::Draw()
{
	switch(m_step) 
	{
	case 0:
	case 1:	
		{
			float pC[3];
			m_app->GetViewPort()->GetPainter()->GetUserColorPoints(pC[0],pC[1],pC[2]);
			m_app->GetViewPort()->GetPainter()->SetCurColor(pC[0],pC[1],pC[2]);
			m_app->GetViewPort()->GetPainter()->DrawPoint(m_cur_pnt);

			if (m_step==1)
			{
				m_app->GetViewPort()->GetPainter()->DrawPoint(m_first_pnt);
				SG_LINE ln;
				ln.p1 = m_first_pnt;
				ln.p2 = m_cur_pnt;
				m_app->GetViewPort()->GetPainter()->GetUserColorLines(pC[0],pC[1],pC[2]);
				m_app->GetViewPort()->GetPainter()->SetCurColor(pC[0],pC[1],pC[2]);
				m_app->GetViewPort()->GetPainter()->DrawLine(ln);
			}
		}
		break;
	case 2:
		{
			float pC[3];
			m_app->GetViewPort()->GetPainter()->GetUserColorPoints(pC[0],pC[1],pC[2]);
			m_app->GetViewPort()->GetPainter()->SetCurColor(pC[0],pC[1],pC[2]);
			m_app->GetViewPort()->GetPainter()->DrawPoint(m_cur_pnt);
			m_app->GetViewPort()->GetPainter()->DrawPoint(m_first_pnt);
			m_app->GetViewPort()->GetPainter()->DrawPoint(m_second_pnt);
			m_app->GetViewPort()->GetPainter()->GetUserColorLines(pC[0],pC[1],pC[2]);
			m_app->GetViewPort()->GetPainter()->SetCurColor(pC[0],pC[1],pC[2]);
			SG_LINE ln;
			ln.p1 = m_first_pnt;
			ln.p2 = m_second_pnt;
			m_app->GetViewPort()->GetPainter()->DrawLine(ln);
			SG_CIRCLE tmpC;
			tmpC.normal = m_dir;
			tmpC.center = m_first_pnt;
			tmpC.radius = m_rad_1;
			m_app->GetViewPort()->GetPainter()->DrawCircle(tmpC);
		}
		break;
	case 3:
		{
			float pC[3];
			m_app->GetViewPort()->GetPainter()->GetUserColorPoints(pC[0],pC[1],pC[2]);
			m_app->GetViewPort()->GetPainter()->SetCurColor(pC[0],pC[1],pC[2]);
			m_app->GetViewPort()->GetPainter()->DrawPoint(m_cur_pnt);
			m_app->GetViewPort()->GetPainter()->DrawPoint(m_first_pnt);
			m_app->GetViewPort()->GetPainter()->DrawPoint(m_second_pnt);
			m_app->GetViewPort()->GetPainter()->GetUserColorLines(pC[0],pC[1],pC[2]);
			m_app->GetViewPort()->GetPainter()->SetCurColor(pC[0],pC[1],pC[2]);
			SG_LINE ln;
			ln.p1 = m_first_pnt;
			ln.p2 = m_second_pnt;
			m_app->GetViewPort()->GetPainter()->DrawLine(ln);
			SG_CIRCLE tmpC;
			tmpC.normal = m_dir;
			tmpC.center = m_second_pnt;
			tmpC.radius = m_rad_2;
			m_app->GetViewPort()->GetPainter()->DrawCircle(tmpC);
			tmpC.center = m_first_pnt;
			tmpC.radius = m_rad_1;
			m_app->GetViewPort()->GetPainter()->DrawCircle(tmpC);
		}
		break;
	default:
		ASSERT(0);
	}
}

void  ConeCommand::OnEnter()
{
	SWITCH_RESOURCE
	switch(m_step) 
	{
	case 0:
		{
			ASSERT(m_get_first_point_panel);
			m_get_first_point_panel->GetPoint(m_first_pnt.x,
				m_first_pnt.y,
				m_first_pnt.z);
			m_step++;
			m_app->GetCommandPanel()->SetActiveRadio(m_step);
			m_message.LoadString(IDS_CYL_ENTER_SEC_P);
			m_app->PutMessage(IApplicationInterface::MT_MESSAGE,
				m_message);
		}
		break;
	case 1:
		{
			ASSERT(m_get_second_point_panel);
			m_get_second_point_panel->GetPoint(m_second_pnt.x,
				m_second_pnt.y,
				m_second_pnt.z);
			m_length = sgSpaceMath::PointsDistance(m_first_pnt,m_second_pnt);
			if (m_length<0.0001)
			{
				m_message.LoadString(IDS_ERROR_ZERO_LENGTH);
				m_app->PutMessage(IApplicationInterface::MT_ERROR,
					m_message);
				return;
			}
			m_dir.x = m_second_pnt.x-m_first_pnt.x;
			m_dir.y = m_second_pnt.y-m_first_pnt.y;
			m_dir.z = m_second_pnt.z-m_first_pnt.z;
			sgSpaceMath::NormalVector(m_dir);
			m_step++;
			m_app->GetCommandPanel()->SetActiveRadio(m_step);
			m_message.LoadString(IDS_CONE_ENTER_FIR_RAD);
			m_app->PutMessage(IApplicationInterface::MT_MESSAGE,
				m_message);
		}
		break;
	case 2:
		{
			double rd = m_get_r1_panel->GetNumber();
			
			m_rad_1 = rd;
			m_step++;
			m_app->GetCommandPanel()->SetActiveRadio(m_step);
			m_message.LoadString(IDS_CONE_ENTER_SEC_RAD);
			m_app->PutMessage(IApplicationInterface::MT_MESSAGE,
				m_message);
		}
		break;
	case 3:
		{
			double rd = m_get_r2_panel->GetNumber();
			if (fabs(rd)<0.0001 && fabs(m_rad_1)<0.0001)
			{
				m_message.LoadString(IDS_ERROR_ZERO_BOTH_RADS);
				m_app->PutMessage(IApplicationInterface::MT_ERROR,
					m_message);
				return;
			}
			
			sgCCone* cone = sgCreateCone(fabs(m_rad_1),fabs(rd),fabs(m_length),24);
			if (!cone)
				return;

			cone->InitTempMatrix()->VectorToZAxe(m_dir);
			cone->GetTempMatrix()->Inverse();
			cone->GetTempMatrix()->Translate(m_first_pnt);
			cone->ApplyTempMatrix();
			cone->DestroyTempMatrix();

			CString nm;
			nm.LoadString(IDS_TOOLTIP_THIRD);
			CString nmInd;
			nmInd.Format("%i",cone_name_index);
			nm+=nmInd;
			cone->SetName(nm);
			
			sgGetScene()->StartUndoGroup();
			sgGetScene()->AttachObject(cone);
			m_app->ApplyAttributes(cone);
			sgGetScene()->EndUndoGroup();
			cone_name_index++;
			
			m_app->GetViewPort()->InvalidateViewPort();
			NewScenar();
		}
		break;
	default:
		ASSERT(0);
		break;
	}
}

unsigned int  ConeCommand::GetItemsCount()
{
	return 0;
}

void         ConeCommand::GetItem(unsigned int, CString&)
{
	SWITCH_RESOURCE
}

void     ConeCommand::GetItemState(unsigned int, bool&, bool&)
{
}

HBITMAP     ConeCommand::GetItemBitmap(unsigned int)
{
	return NULL;
}

void         ConeCommand::Run(unsigned int)
{
}

void         ConeCommand::NewScenar()
{
	SWITCH_RESOURCE
	m_app->GetCommandPanel()->RemoveAllDialogs();
	CString lab;
	lab.LoadString(IDS_FIRST_AXE_PNT);
	m_get_first_point_panel = reinterpret_cast<IGetPointPanel*>(m_app->
		GetCommandPanel()->
		AddDialog(IBaseInterfaceOfGetDialogs::GET_POINT_DLG,lab,true));
	

	lab.LoadString(IDS_SECOND_AXE_PNT);
	m_get_second_point_panel = reinterpret_cast<IGetPointPanel*>(m_app->
		GetCommandPanel()->
		AddDialog(IBaseInterfaceOfGetDialogs::GET_POINT_DLG,lab,true));
	

	lab.LoadString(IDS_RADIUS_1);
	m_get_r1_panel = reinterpret_cast<IGetNumberPanel*>(m_app->
		GetCommandPanel()->
		AddDialog(IBaseInterfaceOfGetDialogs::GET_NUMBER_DLG,lab,true));


	lab.LoadString(IDS_RADIUS_2);
	m_get_r2_panel = reinterpret_cast<IGetNumberPanel*>(m_app->
		GetCommandPanel()->
		AddDialog(IBaseInterfaceOfGetDialogs::GET_NUMBER_DLG,lab,true));
	
	lab.LoadString(IDS_CYL_ENTER_FIRST_P);
	m_app->PutMessage(IApplicationInterface::MT_MESSAGE,lab);

	m_app->GetCommandPanel()->SetActiveRadio(0);

	m_step=0;
}