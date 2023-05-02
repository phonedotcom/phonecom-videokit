//
//  SipRegisterInfo.h
//  PhoneSipManager
//
//  Created by vTechnolabs on 03/03/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SipRegisterInfo : NSObject <NSCopying>

/*! @brief voip server like - "stage.sip.phone.com" */
@property (nonatomic, copy) NSString* _Nonnull domain;

/*! @brief user id */
@property (nonatomic, copy) NSString* _Nonnull user;

/*! @brief user password */
@property (nonatomic, copy) NSString* _Nonnull password;

/*! @brief transport protocol like "tcp" */
@property (nonatomic, copy) NSString* _Nonnull protocol;

/*! @brief unique device identifier */
@property (nonatomic, copy) NSString* _Nonnull deviceToken;

/*! @brief A value that indicates whether debugMode is ON or OFF. On = 1, Off = 0 */
@property (nonatomic, copy) NSString* _Nonnull debugMode;

/*! @brief device type like "iphone" */
@property (nonatomic, copy) NSString* _Nonnull deviceType;

/*! @brief app version */
@property (nonatomic, copy) NSString* _Nonnull appVersion;

/*! @brief app bundle identifier, use - Bundle.main.bundleIdentifier */
@property (nonatomic, copy) NSString* _Nonnull applicationBundleID;

/*! @brief device info, use - UIDevice.current.identifierForVendor!.uuidString */
@property (nonatomic, copy) NSString* _Nonnull deviceInfo;

/*! @brief application ID like "arn:aws:sns:us-west-2:467525865813:app/APNS_VOIP/Liftmaster" */
@property (nonatomic, copy) NSString* _Nonnull applicationId;

@property (nonatomic, copy) NSString* _Nonnull voipID;
@property (nonatomic, copy) NSString* _Nonnull voipPhoneID;
@property (nonatomic, copy) NSString* _Nonnull logFileName;
@property (nonatomic) BOOL srtp;

@end

NS_ASSUME_NONNULL_END
