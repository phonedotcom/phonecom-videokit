//
//  VOIPConstant.h
//  MobileOffice
//
//  Created by Labs108 on 02/10/17.
//  Copyright © 2017 Phone.Com. All rights reserved.
//

#import <CallKit/CallKit.h>
#import "CToObjCBridge.h"
#import <UIKit/UIKit.h>

@class SipCallInfo;

static const NSInteger ADDefaultMaximumCallsPerCallGroup = 1;
static const NSInteger ADDefaultMaximumCallGroups = 1;

static NSString * const _Nonnull SIPCallConnecting = @"Connecting...";
static NSString * const _Nonnull SIPCallConnected = @"Connected";
static NSString * const _Nonnull SIPCallDisconnected = @"Disconnected";
static NSString * const _Nonnull SIPCallHold = @"Hold";
static NSString * const _Nonnull SIPCallActive = @"Active";
static NSString * const _Nonnull SIPCallCalling = @"calling...";
static NSString * const _Nonnull SIPCallRinging = @"Ringing....";
static NSString * const _Nonnull SIPCall = @"call";

static const NSString * _Nonnull SIPCallLinked_UUID = @"linked_uuid";
static const NSString * _Nonnull SIPCallFrom = @"from";
static const NSString * _Nonnull SIPCallSlot = @"slot";
static const NSString * _Nonnull SIPCallServer = @"server";
static const NSString * _Nonnull SIPCallStatus = @"status";
static const NSString * _Nonnull SIPCallCallerContactName = @"caller_contact_name";

#define SIPCallTypeInComing @"incoming"
#define SIPCallStateNotification @"notification"

#define SIPCallStatusAnswered @"answered"
#define SIPCallStatusCanceled @"canceled"


typedef NS_ENUM(NSInteger, CallKitCallActionType) {
    CallKitCallActionTypeStart,
    CallKitCallActionTypeEnd,
    CallKitCallActionTypeAnswer,
    CallKitCallActionTypeMute,
    CallKitCallActionTypeHeld
};

typedef NS_ENUM(NSInteger, CallKitCallState) {
    CallKitCallStatePending,
    CallKitCallStateConnecting,
    CallKitCallStateConnected,
    CallKitCallStateEnded,
    CallKitCallStateEndedWithFailure,
    CallKitCallStateEndedUnanswered,
    CallKitCallStateEndedCancelled
};

typedef void (^SipCallKitManagerCompletion)(NSError *_Nullable error);
typedef void (^SipCallKitActionNotificationBlock)(CXCallAction *_Nullable action, CallKitCallActionType actionType);
//typedef void (^VoIPStoreManagerRegistrationCompletion)(NSString *_Nullable callNumber);

typedef void (^OnSipAccountRegistered)(SIP_STORE_ACCOUNT_STATE state);
typedef void (^OnCallDisConnected)(NSString *_Nonnull callUDID);

typedef void (^OnCallAccepted)(NSString *_Nonnull callUDID);
typedef void (^OnCallRejected)(NSString *_Nonnull callUDID);
typedef void (^OnCallRejectFullfillHandler)(NSString *_Nonnull callUDID);


typedef void (^OnCallOnHoldCompletion)(NSString *_Nonnull callUDID);
typedef void (^OnIncomingCallRecieved)(SipCallInfo * _Nonnull call);

typedef void (^OnOutgoingCallStateChanged)(NSString *_Nonnull callUDID, SIP_CALL_STATE state, NSString *_Nonnull codecName);
typedef void (^OnIncomingVideoCaptured)(UIView *_Nonnull video, int index, NSString *_Nonnull callUDID);

typedef void (^WillInitiatInComingCall)(SipCallInfo * _Nonnull call);
typedef void (^OnIntialisedToMakeCall)(SIP_STORE_ACCOUNT_STATE state);
typedef void (^OnCallUnHoldCompletion)(NSString *_Nonnull callUDID);

typedef void (^OnMediaInfoUpadted)(SIP_CALL_MEDIA_EVENT event, NSString *_Nonnull callUDID);

typedef void (^callsMergedCompletion)(BOOL val);

typedef enum {
    SIP_STORE_SYSTEM_STATE_NOT_INITED,
    SIP_STORE_SYSTEM_STATE_INITED,
    SIP_STORE_SYSTEM_STATE_INITIATING
    
} SIP_STORE_SYSTEM_STATE;

// unified state combines all possible factors and returns a value to the UI
typedef enum {
    SIP_STORE_UNIFIED_STATUS_OK,
    SIP_STORE_UNIFIED_STATUS_UNAVAILABLE,
    SIP_STORE_UNIFIED_STATUS_ERROR,
    
} SIP_STORE_UNIFIED_STATUS;
