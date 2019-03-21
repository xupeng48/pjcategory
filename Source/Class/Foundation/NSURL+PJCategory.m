//
//  NSURL+PJRadio.m
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import "NSURL+PJCategory.h"

@implementation NSURL (PJCategory)

- (NSURL *)URLByAppendingQueryName:(NSString *)name value:(NSString *)value {
    NSURLComponents * components = [NSURLComponents componentsWithURL:self resolvingAgainstBaseURL:NO];
    NSArray * queryItems = [components queryItems];
    NSMutableArray * updatedQueryItems = [NSMutableArray new];
    if (queryItems) {
        [updatedQueryItems addObjectsFromArray:queryItems];
    }
    NSURLQueryItem * item = [NSURLQueryItem queryItemWithName:name value:value];
    [updatedQueryItems addObject:item];
    NSURL * url = [components URL];
    return url;
}

- (NSString *)queryValueForKey:(NSString *)key {
    NSURLComponents * components = [NSURLComponents componentsWithURL:self resolvingAgainstBaseURL:NO];
    NSArray * queryItems = [components queryItems];
    for (NSURLQueryItem * item in queryItems) {
        if ([item.name isEqualToString:key]) {
            return item.value;
        }
    }
    return nil;
}

- (NSDictionary *)queryDictionary {
    NSURLComponents * components = [NSURLComponents componentsWithURL:self resolvingAgainstBaseURL:NO];
    NSArray * queryItems = [components queryItems];
    NSMutableDictionary * result = [NSMutableDictionary new];
    for (NSURLQueryItem * item in queryItems) {
        NSString * value = item.value ?: @"";
        value = [value stringByRemovingPercentEncoding];
        NSString * key = [item.name stringByRemovingPercentEncoding];
        [result setValue:value forKey:key];
    }
    return [[NSDictionary alloc] initWithDictionary:result];
}

@end
