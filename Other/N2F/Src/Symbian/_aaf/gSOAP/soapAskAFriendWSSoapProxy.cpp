/* soapAskAFriendWSSoapProxy.cpp
   Generated by gSOAP 2.7.10 from askafriend.h
   Copyright(C) 2000-2008, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#include "soapAskAFriendWSSoapProxy.h"

AskAFriendWSSoapProxy::AskAFriendWSSoapProxy()
{	AskAFriendWSSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

AskAFriendWSSoapProxy::AskAFriendWSSoapProxy(const struct soap &soap)
{	AskAFriendWSSoapProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_copy_context(this, &soap);
}

AskAFriendWSSoapProxy::AskAFriendWSSoapProxy(soap_mode iomode)
{	AskAFriendWSSoapProxy_init(iomode, iomode);
}

AskAFriendWSSoapProxy::AskAFriendWSSoapProxy(soap_mode imode, soap_mode omode)
{	AskAFriendWSSoapProxy_init(imode, omode);
}

void AskAFriendWSSoapProxy::AskAFriendWSSoapProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns3", "http://tempuri.org/AskAFriendWSSoap", NULL, NULL},
	{"ns1", "http://tempuri.org/", NULL, NULL},
	{"ns4", "http://tempuri.org/AskAFriendWSSoap12", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	if (!this->namespaces)
		this->namespaces = namespaces;
}

AskAFriendWSSoapProxy::~AskAFriendWSSoapProxy()
{ }

void AskAFriendWSSoapProxy::soap_noheader()
{	header = NULL;
}

const SOAP_ENV__Fault *AskAFriendWSSoapProxy::soap_fault()
{	return this->fault;
}

const char *AskAFriendWSSoapProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *AskAFriendWSSoapProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int AskAFriendWSSoapProxy::soap_close_socket()
{	return soap_closesock(this);
}

void AskAFriendWSSoapProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void AskAFriendWSSoapProxy::soap_stream_fault(std::ostream& os)
{	return ::soap_stream_fault(this, os);
}

char *AskAFriendWSSoapProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int AskAFriendWSSoapProxy::SubmitQuestion(_ns1__SubmitQuestion *ns1__SubmitQuestion, _ns1__SubmitQuestionResponse *ns1__SubmitQuestionResponse)
{	struct soap *soap = this;
	struct __ns3__SubmitQuestion soap_tmp___ns3__SubmitQuestion;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://services.next2friends.com/n2fwebservices/askafriend.asmx";
	soap_action = "http://tempuri.org/SubmitQuestion";
	soap->encodingStyle = NULL;
	soap_tmp___ns3__SubmitQuestion.ns1__SubmitQuestion = ns1__SubmitQuestion;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns3__SubmitQuestion(soap, &soap_tmp___ns3__SubmitQuestion);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns3__SubmitQuestion(soap, &soap_tmp___ns3__SubmitQuestion, "-ns3:SubmitQuestion", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns3__SubmitQuestion(soap, &soap_tmp___ns3__SubmitQuestion, "-ns3:SubmitQuestion", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__SubmitQuestionResponse)
		return soap_closesock(soap);
	ns1__SubmitQuestionResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__SubmitQuestionResponse->soap_get(soap, "ns1:SubmitQuestionResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int AskAFriendWSSoapProxy::AttachPhoto(_ns1__AttachPhoto *ns1__AttachPhoto, _ns1__AttachPhotoResponse *ns1__AttachPhotoResponse)
{	struct soap *soap = this;
	struct __ns3__AttachPhoto soap_tmp___ns3__AttachPhoto;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://services.next2friends.com/n2fwebservices/askafriend.asmx";
	soap_action = "http://tempuri.org/AttachPhoto";
	soap->encodingStyle = NULL;
	soap_tmp___ns3__AttachPhoto.ns1__AttachPhoto = ns1__AttachPhoto;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns3__AttachPhoto(soap, &soap_tmp___ns3__AttachPhoto);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns3__AttachPhoto(soap, &soap_tmp___ns3__AttachPhoto, "-ns3:AttachPhoto", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns3__AttachPhoto(soap, &soap_tmp___ns3__AttachPhoto, "-ns3:AttachPhoto", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__AttachPhotoResponse)
		return soap_closesock(soap);
	ns1__AttachPhotoResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__AttachPhotoResponse->soap_get(soap, "ns1:AttachPhotoResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int AskAFriendWSSoapProxy::CompleteQuestion(_ns1__CompleteQuestion *ns1__CompleteQuestion, _ns1__CompleteQuestionResponse *ns1__CompleteQuestionResponse)
{	struct soap *soap = this;
	struct __ns3__CompleteQuestion soap_tmp___ns3__CompleteQuestion;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://services.next2friends.com/n2fwebservices/askafriend.asmx";
	soap_action = "http://tempuri.org/CompleteQuestion";
	soap->encodingStyle = NULL;
	soap_tmp___ns3__CompleteQuestion.ns1__CompleteQuestion = ns1__CompleteQuestion;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns3__CompleteQuestion(soap, &soap_tmp___ns3__CompleteQuestion);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns3__CompleteQuestion(soap, &soap_tmp___ns3__CompleteQuestion, "-ns3:CompleteQuestion", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns3__CompleteQuestion(soap, &soap_tmp___ns3__CompleteQuestion, "-ns3:CompleteQuestion", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__CompleteQuestionResponse)
		return soap_closesock(soap);
	ns1__CompleteQuestionResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__CompleteQuestionResponse->soap_get(soap, "ns1:CompleteQuestionResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int AskAFriendWSSoapProxy::GetPrivateAAFQuestion(_ns1__GetPrivateAAFQuestion *ns1__GetPrivateAAFQuestion, _ns1__GetPrivateAAFQuestionResponse *ns1__GetPrivateAAFQuestionResponse)
{	struct soap *soap = this;
	struct __ns3__GetPrivateAAFQuestion soap_tmp___ns3__GetPrivateAAFQuestion;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://services.next2friends.com/n2fwebservices/askafriend.asmx";
	soap_action = "http://tempuri.org/GetPrivateAAFQuestion";
	soap->encodingStyle = NULL;
	soap_tmp___ns3__GetPrivateAAFQuestion.ns1__GetPrivateAAFQuestion = ns1__GetPrivateAAFQuestion;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns3__GetPrivateAAFQuestion(soap, &soap_tmp___ns3__GetPrivateAAFQuestion);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns3__GetPrivateAAFQuestion(soap, &soap_tmp___ns3__GetPrivateAAFQuestion, "-ns3:GetPrivateAAFQuestion", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns3__GetPrivateAAFQuestion(soap, &soap_tmp___ns3__GetPrivateAAFQuestion, "-ns3:GetPrivateAAFQuestion", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__GetPrivateAAFQuestionResponse)
		return soap_closesock(soap);
	ns1__GetPrivateAAFQuestionResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetPrivateAAFQuestionResponse->soap_get(soap, "ns1:GetPrivateAAFQuestionResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int AskAFriendWSSoapProxy::GetMyAAFQuestions(_ns1__GetMyAAFQuestions *ns1__GetMyAAFQuestions, _ns1__GetMyAAFQuestionsResponse *ns1__GetMyAAFQuestionsResponse)
{	struct soap *soap = this;
	struct __ns3__GetMyAAFQuestions soap_tmp___ns3__GetMyAAFQuestions;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://services.next2friends.com/n2fwebservices/askafriend.asmx";
	soap_action = "http://tempuri.org/GetMyAAFQuestions";
	soap->encodingStyle = NULL;
	soap_tmp___ns3__GetMyAAFQuestions.ns1__GetMyAAFQuestions = ns1__GetMyAAFQuestions;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns3__GetMyAAFQuestions(soap, &soap_tmp___ns3__GetMyAAFQuestions);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns3__GetMyAAFQuestions(soap, &soap_tmp___ns3__GetMyAAFQuestions, "-ns3:GetMyAAFQuestions", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns3__GetMyAAFQuestions(soap, &soap_tmp___ns3__GetMyAAFQuestions, "-ns3:GetMyAAFQuestions", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__GetMyAAFQuestionsResponse)
		return soap_closesock(soap);
	ns1__GetMyAAFQuestionsResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetMyAAFQuestionsResponse->soap_get(soap, "ns1:GetMyAAFQuestionsResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int AskAFriendWSSoapProxy::GetNewAAFQuestionCommentIDs(_ns1__GetNewAAFQuestionCommentIDs *ns1__GetNewAAFQuestionCommentIDs, _ns1__GetNewAAFQuestionCommentIDsResponse *ns1__GetNewAAFQuestionCommentIDsResponse)
{	struct soap *soap = this;
	struct __ns3__GetNewAAFQuestionCommentIDs soap_tmp___ns3__GetNewAAFQuestionCommentIDs;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://services.next2friends.com/n2fwebservices/askafriend.asmx";
	soap_action = "http://tempuri.org/GetNewAAFQuestionCommentIDs";
	soap->encodingStyle = NULL;
	soap_tmp___ns3__GetNewAAFQuestionCommentIDs.ns1__GetNewAAFQuestionCommentIDs = ns1__GetNewAAFQuestionCommentIDs;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns3__GetNewAAFQuestionCommentIDs(soap, &soap_tmp___ns3__GetNewAAFQuestionCommentIDs);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns3__GetNewAAFQuestionCommentIDs(soap, &soap_tmp___ns3__GetNewAAFQuestionCommentIDs, "-ns3:GetNewAAFQuestionCommentIDs", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns3__GetNewAAFQuestionCommentIDs(soap, &soap_tmp___ns3__GetNewAAFQuestionCommentIDs, "-ns3:GetNewAAFQuestionCommentIDs", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__GetNewAAFQuestionCommentIDsResponse)
		return soap_closesock(soap);
	ns1__GetNewAAFQuestionCommentIDsResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetNewAAFQuestionCommentIDsResponse->soap_get(soap, "ns1:GetNewAAFQuestionCommentIDsResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int AskAFriendWSSoapProxy::GetAAFResponse(_ns1__GetAAFResponse *ns1__GetAAFResponse, _ns1__GetAAFResponseResponse *ns1__GetAAFResponseResponse)
{	struct soap *soap = this;
	struct __ns3__GetAAFResponse soap_tmp___ns3__GetAAFResponse;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://services.next2friends.com/n2fwebservices/askafriend.asmx";
	soap_action = "http://tempuri.org/GetAAFResponse";
	soap->encodingStyle = NULL;
	soap_tmp___ns3__GetAAFResponse.ns1__GetAAFResponse = ns1__GetAAFResponse;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns3__GetAAFResponse(soap, &soap_tmp___ns3__GetAAFResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns3__GetAAFResponse(soap, &soap_tmp___ns3__GetAAFResponse, "-ns3:GetAAFResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns3__GetAAFResponse(soap, &soap_tmp___ns3__GetAAFResponse, "-ns3:GetAAFResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__GetAAFResponseResponse)
		return soap_closesock(soap);
	ns1__GetAAFResponseResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetAAFResponseResponse->soap_get(soap, "ns1:GetAAFResponseResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int AskAFriendWSSoapProxy::GetAAFComments(_ns1__GetAAFComments *ns1__GetAAFComments, _ns1__GetAAFCommentsResponse *ns1__GetAAFCommentsResponse)
{	struct soap *soap = this;
	struct __ns3__GetAAFComments soap_tmp___ns3__GetAAFComments;
	const char *soap_action = NULL;
	if (!soap_endpoint)
		soap_endpoint = "http://services.next2friends.com/n2fwebservices/askafriend.asmx";
	soap_action = "http://tempuri.org/GetAAFComments";
	soap->encodingStyle = NULL;
	soap_tmp___ns3__GetAAFComments.ns1__GetAAFComments = ns1__GetAAFComments;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___ns3__GetAAFComments(soap, &soap_tmp___ns3__GetAAFComments);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns3__GetAAFComments(soap, &soap_tmp___ns3__GetAAFComments, "-ns3:GetAAFComments", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns3__GetAAFComments(soap, &soap_tmp___ns3__GetAAFComments, "-ns3:GetAAFComments", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns1__GetAAFCommentsResponse)
		return soap_closesock(soap);
	ns1__GetAAFCommentsResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__GetAAFCommentsResponse->soap_get(soap, "ns1:GetAAFCommentsResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */