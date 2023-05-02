//
//  IncomingPushCallObject.h
//  MobileOffice
//
//  Created by Dheeraj Katarya on 4/5/17.
//  Copyright © 2017 Phone.Com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IncomingPushCallObject : NSObject

/*! @brief is call answered on other device */
@property (nonatomic,readwrite)BOOL answered;
@property (nonatomic,readwrite)BOOL callStatusUpdate;

/*! @brief call canceled on other device */
@property (nonatomic,readwrite)BOOL canceled;
@property (nonatomic,strong) NSString *deviceUUidString;

/*! @brief caller number */
@property (nonatomic,strong) NSString *from;

/*! @brief unique id to identify call */
@property (nonatomic,strong) NSString *linkedUUidString;

/*! @brief voip server */
@property (nonatomic,strong) NSString *server;

/*! @brief call parking ID - user can park call using this ID */
@property (nonatomic,strong) NSString *slot;

/*! @brief call state like - @"calling", @"ringing" */
@property (nonatomic,strong) NSString *state;

/*! @brief call status like - @"answered" and @"canceled" */
@property (nonatomic,strong) NSString *status;

/*! @brief It contains call type like - @"outgoing", @"incoming" */
@property (nonatomic,strong) NSString *type;

@property (nonatomic,strong) NSUUID *deviceUUid;

/*! @brief unique id to identify call */
@property (nonatomic,strong) NSUUID *linkedUUID;

/*! @brief caller name */
@property (nonatomic,strong) NSString *callerName;


/*!
   @brief       Initializes and returns IncomingPushCallObject object.

   @param       pushPayloadDictionary
                Contains all info like server, slot, status - to populate IncomingPushCallObject object
 
  @return       An initialized IncomingPushCallObject object.
*/
- (instancetype)initWithPushNotifyPayload:(NSDictionary *)pushPayloadDictionary;

@end
