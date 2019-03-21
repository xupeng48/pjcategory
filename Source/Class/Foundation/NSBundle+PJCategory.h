//
//  NSBundle+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSBundle (PJCategory)

/**
 一组当前客户端解析图片的顺序，比如：iPhone6 Plus:@[@3,@2,@1]
 */
+ (NSArray<NSNumber *> *)preferredScales;

@end
