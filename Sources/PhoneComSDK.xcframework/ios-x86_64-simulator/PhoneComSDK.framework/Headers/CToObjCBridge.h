//
//  ObjC-C++Bridge.h
//  MobileOffice
//
//  Created by Dheeraj Katarya on 3/11/16.
//  Copyright (c) 2014 Phone.com. All rights reserved.
//

#ifndef MobileOffice_ObjC_C__Bridge_h
#define MobileOffice_ObjC_C__Bridge_h


#define MAX_CALLS_ARRAY_SIZE                            4

typedef enum
{
    SIP_CALL_STATE_NONE,
    SIP_CALL_STATE_OUTBOUND_CALLING,
    SIP_CALL_STATE_INBOUND_CALLING,
    SIP_CALL_STATE_CONNECTED,
    SIP_CALL_STATE_DISCONNECTED,
	SIP_CALL_STATE_HOLD,
	SIP_CALL_STATE_ACTIVE,
	SIP_CALL_STATE_RINGING,
	SIP_CALL_STATE_VIDEO_INBOUND_CALLING,
	SIP_CALL_STATE_VIDEO_OUTBOUND_CALLING,
	SIP_CALL_STATE_STREAM_STARTED_WITH_CODEC,
	SIP_CALL_STATE_DISCONNECTED_OTHER,
	SIP_CALL_STATE_CONNECTING,
	SIP_CALL_STATE_REMOTE_DISCONNECTED,
    SIP_CALL_STATE_DISCONNECTING


	
}SIP_CALL_STATE;

typedef enum
{
    SIP_CALL_EVENT_MEDIA_TP_ERR,
    SIP_CALL_EVENT_KEYFRAME_MISSING,
    SIP_CALL_EVENT_VID_DEV_ERROR,
    SIP_CALL_EVENT_KEYFRAME_FOUND,
    SIP_CALL_EVENT_WND_RESIZED,
    SIP_CALL_EVENT_WND_CLOSED,
    SIP_CALL_EVENT_WND_CLOSING,
    SIP_CALL_EVENT_RX_RTCP_FB,
    SIP_CALL_EVENT_AUD_DEV_ERROR,
    SIP_CALL_EVENT_FMT_CHANGED
    
}SIP_CALL_MEDIA_EVENT;

typedef enum
{
    SIP_STORE_ACCOUNT_STATE_UNREGISTERED,
    SIP_STORE_ACCOUNT_STATE_REGISTERING,
    SIP_STORE_ACCOUNT_STATE_REGISTERED,
    SIP_STORE_ACCOUNT_STATE_ERROR_CREDS,
    
}SIP_STORE_ACCOUNT_STATE;


void updateCallState(SIP_CALL_STATE state, const char * _Nonnull callUDID ,const char * _Nullable msgbody , long  callDuration);
void updateRegistrationState(SIP_STORE_ACCOUNT_STATE state);
void updateCallVideoInfo(int wid , int index , const char * _Nonnull callUUID);
void updateCallCodecName(const char * _Nonnull codec, const char * _Nonnull callUUID);

void updateMediaInfo(SIP_CALL_MEDIA_EVENT event , const char * _Nonnull callUUID);

void startOutboundRingingTone(void);
void stopOutboundRingingTone(void);

void newIncomingCall(int callid , const char * _Nullable prmmessage);
void newIncomingMessage(const char * _Nullable messagebody);

#endif
