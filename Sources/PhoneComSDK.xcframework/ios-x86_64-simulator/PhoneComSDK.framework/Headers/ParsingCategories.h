//
//  ParsingCategories.h
//  MobileOffice
//
//  Created by Dheeraj Katarya on 15/11/15.
//  Copyright (c) 2015 Phone.Com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (StringUtilities)

- (BOOL)hasValue;
- (BOOL)isTrue;
- (NSString *)getSafeStringValue;
- (NSString *)getTrueFalseString;

@end

@interface NSArray (ArrayUtilties)

- (BOOL)hasValues;

@end
