//
//  UIResponder+PJCategory.m
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import "UIResponder+PJCategory.h"

@implementation UIResponder(PJCategory)

- (id)pj_findClosetResponderInResponderChainWith:(Class)objClass {
    UIResponder *next = self;
    do {
        next = [next nextResponder];
        if ([next isKindOfClass:objClass]) { break; }
    } while (next != nil);
    
    return [next isKindOfClass:objClass] ? next : nil;
}

- (id)pj_findClosetControllerInResponderChain {
    return [self pj_findClosetResponderInResponderChainWith:[UIViewController class]];
}

@end
