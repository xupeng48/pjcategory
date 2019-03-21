//
//  NSNumber+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSNumber (PJCategory)

/**
 根据字符串创建Number
 
 解析规则：
 @{ @"true" :   @(YES),
    @"yes" :    @(YES),
    @"false" :  @(NO),
    @"no" :     @(NO),
    @"nil" :    [NSNull null],
    @"null" :   [NSNull null],
    @"<null>" : [NSNull null]}
 
 */
+ (nullable NSNumber *)numberWithString:(NSString *)string;

/**
 23 -> "23"
 23.5 -> "23.5"
 23.55 -> "23.55"
 23.554 -> "23.55"
 23.556 -> "23.56"
*/
- (NSString *)twoDecimalString;

/**
 23 -> "23"
 23.5 -> "23.5"
 23.55 -> "23.55"
 23.554 -> "23.55"
 23.556 -> "23.56"
 */
+ (NSString *)twoDecimalStringWith:(CGFloat)num;

@end

NS_ASSUME_NONNULL_END
