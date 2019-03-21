//
//  NSURL+PJRadio.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (PJCategory)

/**
 添加query

 @param name name
 @param value value
 @return 新的URL
 */
-(NSURL *)URLByAppendingQueryName:(NSString *)name value:(NSString *)value;

/**
 获取query
 */
-(NSString *)queryValueForKey:(NSString *)key;

/**
 以字典的方式返回全部的query
 */
-(NSDictionary *)queryDictionary;

@end

NS_ASSUME_NONNULL_END
