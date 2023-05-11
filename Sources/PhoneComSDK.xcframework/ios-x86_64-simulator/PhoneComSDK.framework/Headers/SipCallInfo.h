//
//  SipCallInfo.h
//  MobileOffice
//
//  Created by Dheeraj Katarya on 5/10/16.
//  Copyright © 2016 Phone.Com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CToObjCBridge.h"
#import "SIPConstant.h"

/*!
    @class       SipCallInfo
    @discussion  SipCallInfo objects carries all information about any call, each SipCallInfo object is uniquely identified by a callUUID
*/

@interface SipCallInfo : NSObject

#pragma mark *** Intialise and destroy sip system ***

/*!
   @brief       Initializes and returns SipCallInfo object.

   @param       call
                SipCallInfo object
 
  @return       An initialized SipCallInfo object.
*/
- (instancetype _Nonnull)initWithIncomingCall:(SipCallInfo *_Nonnull)call;

/*!
   @brief       Initializes and returns SipCallInfo object.

   @param       number
                Number to make call.
 
  @return       An initialized SipCallInfo object.
*/
- (instancetype _Nonnull)initWithNumber:(NSString *_Nonnull)number;

/*!
   @brief       Initializes and returns SipCallInfo object.

   @param       number
                Number to make call.
 
 @param         uuid
                Unique identifier of call object, each SipCallInfo object is uniquely identified by a callUUID
 
  @return       An initialized SipCallInfo object.
*/
- (instancetype _Nonnull)initWithNumber:(NSString *_Nonnull)number callUUID:(NSString *_Nonnull)uuid;


#pragma mark *** Sip call state change handlers ***

/*! @brief Call back handler when call accepted */
@property (copy, nonatomic) OnCallAccepted _Nullable callAcceptedHandler;

/*! @brief Call back handler when call disconnected */
@property (copy, nonatomic) OnCallDisConnected _Nullable callDiconnectedHandler;

/*! @brief Call back handler when call onHold */
@property (copy, nonatomic) OnCallOnHoldCompletion _Nullable callOnHoldCompletionHandler;

/*! @brief Call back handler when call rejected */
@property (copy, nonatomic) OnCallRejected _Nullable callRejectedHandler;
@property (copy, nonatomic) OnCallRejectFullfillHandler _Nullable callRejectFullfillHandler;

/*! @brief Call back handler when call unHold */
@property (copy, nonatomic) OnCallUnHoldCompletion _Nullable callUnHoldCompletionHandler;

/*! @brief Call back handler when call state changes */
@property (copy, nonatomic) OnOutgoingCallStateChanged _Nullable callStateChangedHandler;


#pragma mark *** variables ***

@property (readwrite, nonatomic) BOOL active;

/*! @brief Incoming call is ansered or not - populated from IncomingPushCallObject */
@property (readwrite, nonatomic) BOOL answered;

/*! @brief Incoming call is cancelled or not - populated from IncomingPushCallObject */
@property (readwrite, nonatomic) BOOL canceled;
@property (readwrite, nonatomic) BOOL conferenceCall;

/*! @brief A Boolean value that indicates whether the provider supports video in addition to audio. */
@property (readwrite, nonatomic) BOOL hasVideo;
@property (readwrite, nonatomic) BOOL holdCall;
@property (readwrite, nonatomic) BOOL mute;
@property (readwrite, nonatomic) NSInteger * _Nullable callerContactID;
@property (readwrite, nonatomic) NSInteger callIdx;
@property (readwrite, nonatomic) SIP_CALL_STATE state;

/*! @brief It contains call state like - @"calling", @"ringing" */
@property (strong, nonatomic) NSString * _Nonnull callState;

/*! @brief call status like - @"answered" and @"canceled" */
@property (strong, nonatomic) NSString * _Nonnull callStatus;

/*! @brief It contains call type like - @"outgoing", @"incoming" */
@property (strong, nonatomic) NSString * _Nonnull callType;

/*! @brief unique id to identify call */
@property (strong, nonatomic) NSString * _Nonnull callUUID;
@property (strong, nonatomic) NSString * _Nonnull callerDID;
@property (strong, nonatomic) NSString * _Nonnull codecName;

/*! @brief unique id to identify call */
@property (strong, nonatomic) NSString * _Nonnull linkedUUID;

/*! @brief call parking ID - user can park call using this ID */
@property (strong, nonatomic) NSString * _Nonnull parkingSlot;

/*! @brief voip server */
@property (strong, nonatomic) NSString * _Nonnull routingServer;

/*! @brief caller name */
@property (strong, nonatomic) NSString * _Nullable callerCnam;

/*! @brief caller number generated for call like - sip:505@stage.sip.phone.com;transport=tcp */
@property (strong, nonatomic) NSString * _Nonnull remoteContact;
@property (strong, nonatomic) NSString * _Nonnull pjsuaCallUUID;

@end
