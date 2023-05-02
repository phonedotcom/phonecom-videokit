//
//  PushRegistryManager.h
//  PhoneSipManager
//
//  Created by Phone.com on 09/12/19.
//  Copyright © 2019 Phone.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PushKit/PushKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PushRegistryManagerDelegate <NSObject>

@optional
/*!
    @discussion     This method is invoked when a incoming call push notification has been received for the specified PKPushType.
 
    @param          payload
                    The push payload sent by a developer via APNS server API.
    @param          type
                    This is a PKPushType constant which is present in [registry desiredPushTypes].
    @param          callDidCompleted
                    This completion handler should be called to signify the completion of payload processing.
*/
- (void)didReceivedIncomingCallPayload:(PKPushPayload *)payload forType:(PKPushType)type withCompletionHandler:(void(^)(void))callDidCompleted;

/*!
    @discussion     This method is invoked when new credentials (including push token) have been received for the specified
                    PKPushType.
    @param          token
                    The device token recevied new credentials
*/
- (void)didUpdatePushCredentials:(NSString *)token;

@end

/*!
    @class         PushRegistryManager
    @abstract      PushRegistryManager is a singletn class.
    @discussion    An instance of this class can be used to register for PKPushRegistry. The supported push
                    notification types are listed above as PKPushType constants.
*/
@interface PushRegistryManager : NSObject


#pragma mark *** Sip call handlers ***

@property (nonatomic, weak) id<PushRegistryManagerDelegate> delegate;


#pragma mark *** Intialise singleton object ***

/*!
    @brief       Class funtion to creates singleton instance of PushRegistryManager

    @discussion  A PushRegistryManager singleton instance use to register for PKPushRegistry
    @return      PushRegistryManager
                The singleton instance.
*/
+ (PushRegistryManager *_Nonnull)sharedManager;

/*!
    @brief       Registers the PKPushRegistry object for type 'PKPushTypeVoIP'

    @discussion  The push registry object makes a registration request with the PushKit server. This request is asynchronous, and the success of the request is reported to your                    delegate object. For a successful registration, PushRegistryManager delivers a device token to the delegate.
 
    @see          PKPushRegistry
*/
- (void)registerForPushKit;

/*!
    @brief       Return PKPushRegistry object
 
    @return     pushRegistry
                Object created at the time of 'registerForPushKit' function
*/
- (PKPushRegistry *)pushRegistry;

@end

NS_ASSUME_NONNULL_END
