//
//  SipDataManager.h
//  MobileOffice
//
//  Created by Labs108 on 02/10/17.
//  Copyright © 2017 Phone.Com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SIPConstant.h"
#import <AVFoundation/AVFoundation.h>

@class VoIPCall;
@class IncomingPushCallObject;

/*!
    @class       SipDataManager
    @abstract    SipDataManager is a singletn class.
    @discussion  SipDataManager singleton instance use to manage store and manage Ongoing calls in system
*/

@interface SipDataManager : NSObject

/*! @brief  This variable knows updated System State */
@property SIP_STORE_SYSTEM_STATE voipStoreSystemState;

/*! @brief  This variable knows updated Account State */
@property SIP_STORE_ACCOUNT_STATE voipStoreAccountState;

@property(nonatomic, strong, nonnull) NSString *sipDomain;
@property(nonatomic, strong, nonnull) NSString *sipUser;
@property(nonatomic, strong, nonnull) NSString *sipPassword;

@property(nonatomic, strong, nullable) AVAudioPlayer *audioPlayerOutbound;

/*! @brief Array of all ongoing calls in system */
@property(nonatomic, strong, nonnull) NSMutableArray *arrVoipCalls;

@property(nonatomic, strong, nullable) dispatch_queue_t completionQueue; // Default to mainQueue

+ (SipDataManager *_Nonnull)sharedManager;

/*!
   @brief       Perform search for SipCallInfo object in system

   @param       _NullablecallUUID
                Unique callUUID
 
  @return       SipCallInfo object
*/
- (SipCallInfo *_Nonnull)findVoipCallForUUID:(NSString*_Nonnull)_NullablecallUUID;

/*!
   @brief       Perform search for SipCallInfo object in system

   @param       callIdx
                Unique callId
 
  @return       SipCallInfo object
*/
- (SipCallInfo *_Nonnull)findVoipCallForCallIdx:(int)callIdx;

/*!
   @brief       Perform search for SipCallInfo object in system

   @param       callUDID
                Unique callUUID
 
  @return       SipCallInfo object
*/
- (SipCallInfo *_Nonnull)findVoipCallForUDID:(NSString *_Nullable)callUDID;

/*!
   @brief       Add new call in system calls array

   @param       callInfo
                SipCallInfo object
 
*/
- (void)addNewCall:(SipCallInfo *_Nullable)callInfo;

- (NSString*_Nonnull)createSipDomainUri:(NSString*_Nonnull)domain sipProtocol:(NSString *_Nonnull) protocol;

- (NSString*_Nonnull)createSipUri:(NSString*_Nonnull)number sipDomainPort:(NSString *_Nonnull)domain sipProtocol:(NSString *_Nonnull) protocol;

@end
