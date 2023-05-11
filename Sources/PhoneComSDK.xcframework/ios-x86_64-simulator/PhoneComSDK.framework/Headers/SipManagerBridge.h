//
//  VOIPStore.h
//  MobileOffice

//  Copyright (c) 2014 Phone.com. All rights reserved.
//


/*!
    @class    SipManagerBridge
    @abstract SipManagerBridge is a singletn class.
    @discussion A SipManagerBridge singleton instance use to handle Sip activites like Sip Regiatration, Incoming and OutGoing call,
                all activities related to calls like hold, mute....
*/


#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "SipCallInfo.h"
#import "SipRegisterInfo.h"
#import "PushRegistryManager.h"

@class IncomingPushCallObject;

@interface SipManagerBridge : NSObject  {
  SIP_CALL_STATE _callState;
}

#pragma mark *** Sip call handlers ***

/*! @brief Call back to handle when application registered to SIP server. */
@property (copy, nonatomic) OnSipAccountRegistered _Nullable registerationHandler;

/*! @brief Call back to handle incoming audio call. */
@property (copy, nonatomic) OnIncomingCallRecieved _Nullable incomingCallRecievedHandler;

/*! @brief Call back to handle incoming video call. */
@property (copy, nonatomic) OnIncomingVideoCaptured _Nullable incomingVideoCapturedHandler;

/*! @brief Call back to handle when application registered to SIP server and ready to make a call. */
@property (copy, nonatomic) OnIntialisedToMakeCall _Nullable sipIntialisedToMakeCallHandler;

/*! @brief Call back to manage updated media info. */
@property (copy, nonatomic) OnMediaInfoUpadted _Nullable mediaInfoUpdatedHandler;


#pragma mark *** Intialise singleton object ***

/*!
   @brief Class funtion to creates singleton instance of SipManagerBridge

   @discussion A SipManagerBridge singleton instance use to handle Sip activites like Sip Regiatration, Incoming and OutGoing call,
                all activities related to calls like hold, mute....

   @return SipManagerBridge The singleton instance.
*/
+ (SipManagerBridge *_Nonnull)sharedManager;


/*!
   @brief Class funtion to tell about application state

   @discussion This function returns bool to know about application current state state
        
                To use it, simply call [SipManagerBridge isApplicationInForeGround];

   @return Bool Return true if application state is UIApplicationStateBackground else return false.
*/
+ (BOOL)isApplicationInForeGround;


#pragma mark *** Intialise and destroy sip system ***

/*!
   @brief Will check application registered to SIP server or not.

   @discussion If application is not registered then this method will register it automatically.
                This method will call "registerationHandler" and "sipIntialisedToMakeCallHandler"
 
                Call initSipSystem - (void)initSipSystem:(SipRegisterInfo *_Nonnull)registerInfo before this.
 
  @see - (void)initSipSystem:(SipRegisterInfo *_Nonnull)registerInfo;
*/
- (void)checkVOIPSystemStatus;

/*!
   @brief Perform unregistration and destroy pjsua.

   @discussion Destroy pjsua. Application is recommended to perform graceful shutdown before calling this method (such as unregister the account from the SIP server, terminate presense subscription, and hangup active calls), however, this method will do all of these if it finds there are active sessions that need to be terminated.
*/
- (void)destroyStack;

/*!
   @brief Save values - will requires to create sip account

   @discussion Must call this function before 'checkVOIPSystemStatus'.
   
   @param  registerInfo The input value conatins domain, user, password...
 
   @see SipRegisterInfo
   @see - (void)checkVOIPSystemStatus;
*/
- (void)initSipSystem:(SipRegisterInfo *_Nonnull)registerInfo;

/*!
   @brief Setup CallKit
 
   @param  appName A name for the provider.
 
   @param image A icon image to be displayed for the provider.

   @discussion Must call this method to manage call activities properly.
*/
- (void)setUpCallKitWithName:(NSString * _Nullable )appName image:(UIImage *_Nullable) image;

/*!
   @brief Perform unregistration.

   @discussion Application normally only needs to call this method if it wants to manually to unregister from the server.
*/
- (void)unRegister;
- (void)unRegisterFromPush;


#pragma mark *** Get caller info ***

- (NSString *_Nullable)getCallerCNAM:(NSString *_Nonnull)callUUID; // if the name via caller ID exists, return it here
- (NSString *_Nullable)getCallerDID:(NSString *_Nonnull)callUUID;
- (NSString *_Nullable)getSipDomain;
- (NSString *_Nullable)getSipProtocol;


#pragma mark *** Get account state ***

- (SIP_STORE_ACCOUNT_STATE)getStoreAccountState;
- (SIP_STORE_SYSTEM_STATE)getStoreSystemState;


#pragma mark *** Find SipCallInfo object ***

/*!
   @brief Perform Search for SipCallInfo object

   @discussion This method will find and return the object of SipCallInfo from active calls array.
   
   @param callUUID UUID of call
 
   @return SipCallInfo object
*/
- (SipCallInfo *_Nonnull)findSipCallForUUID:(NSString*_Nonnull)callUUID;


#pragma mark *** Hold, unHold, Mute and UnMute Sip call ***

/*!
   @brief       Hold the call

   @discussion  Pass callUUID of SipCallInfo object on which you want to perfom <b>Hold</b> action.
   
   @param       callUUID UUID of call
 
   @param       handler
                Callback on completion
 */
- (void)holdCall:(NSString *_Nonnull)callUUID onCompletion:(OnCallOnHoldCompletion _Nullable )handler;

/*!
  @brief        Perform Mute on call

  @discussion   Pass callUUID of SipCallInfo object on which you want to perfom <b>Mute</b> action.
  
  @param        callUUID
                UUID of call
 */
- (void)muteOngoingCall:(NSString *_Nonnull)callUUID;

/*!
  @brief        Perform unHold on call

  @discussion   Pass callUUID of SipCallInfo object on which you want to perfom <b>unHold</b> action.
  
  @param        callUUID
                UUID of call
 
  @param        handler
                Callback on completion
*/
- (void)unHoldCall:(NSString *_Nonnull)callUUID onCompletion:(OnCallUnHoldCompletion _Nullable )handler;

/*!
  @brief        Perform unmute on call

  @discussion   Pass callUUID of SipCallInfo object on which you want to perfom <b>unmute</b> action.
 
  @param        callUUID
                UUID of call
*/
- (void)unMuteOngoingCall:(NSString *_Nonnull)callUUID;


#pragma mark *** Make outgoing, incoming & Disconect and transfer Sip call ***

/*!
  @brief            Perform new call actionl

  @discussion       Call this function to make new call
 
  @param            voipCallInfo SipCallInfo object
 
  @param            parkingSlot NSString* object
 
  @param            routingServer NSString* object
                    sip server
 
  @see SipCallInfo
*/
- (BOOL)makeCall:(SipCallInfo* _Nonnull )voipCallInfo parkingSlot:(NSString* _Nullable )parkingSlot routingServer:(NSString* _Nullable )routingServer;

/*!
 @brief             Perform to answer call

 @discussion        Call this function to make new call

 @param             callUUID NSString object
 */
- (void)answerIncomingCall:(NSString *_Nonnull)callUUID;

/*!
 @brief Perform hangup call

 @discussion Hang up all active calls

 */
- (void)hangupAllCalls;

/*!
@brief          Perform hangup call

@discussion     Hang up all active calls

 */
- (void)hangupCallWithUUID:(NSString *_Nonnull)callUUID;

/*!
 @brief         Perform hangup call

 @discussion    Hang up specific call for SipCallInfo object pass in parameter.
 
 @param         callInfo SipCallInfo object
 
 @see           SipCallInfo
 
*/
- (void)makeCallUsingCallInfo:(nonnull SipCallInfo *)callInfo;

/*!
 @brief Perform merge opeartion

 @discussion    Call this method to merge two active calls in the system.
 
 @param         callUuIdA NSString* object source call
 
 @param         callUuIdB NSString* object destination call
 
 @param         handler Callback on completion
  
*/
- (void)mergeCalls:(NSString *_Nonnull)callUuIdA localIdxB:(NSString *_Nonnull)callUuIdB onCompletion:(callsMergedCompletion _Nullable )handler;

/*!
 @brief         Perform call transfer

 @discussion    Initiate call transfer to the specified address. This function will send REFER request to instruct remote call party to initiate a new                  INVITE session to the specified destination/target.
 
 @param         callUUID NSString* object source call
 
 @param         toDestination NSString* object destination number
 
 @param         protocol NSString* object
  
*/
- (void)transferCallWithId:(NSString *_Nonnull)callUUID toDestination:(nonnull NSString *)toDestination protocol:(NSString *_Nonnull)protocol;

/*!
 @brief       Process incoming call from PushKit

 @param       payload PKPushPayload* object
 
 @param      type PKPushType object
 
 @param      callDidCompleted Callback on completion
 
 @see       PushKit framework
  
*/
- (void)processIncomingCallForpayLoad:(PKPushPayload *_Nullable)payload
                              forType:(PKPushType _Nullable )type withCompletionHandler:(void(^_Nullable)(void))callDidCompleted;

#pragma mark *** Supporting ***

- (void)createBackgroundTask;
- (NSInteger)callDurationForCall:(NSString *_Nonnull)callUUID;
- (int)getSipCallsCount;
- (void)activateSoundDev;
- (void)deActivateSoundDev;
- (void)sendDTMFCode:(nonnull NSString *)code callUUID:(NSString *_Nonnull)callUUID;
- (void)updateNetworkTransport;
- (void)updateSipProtocol:(NSString *_Nonnull)protocol;
- (void)reinviteCall:(NSString *_Nonnull)callUUID;

@end




