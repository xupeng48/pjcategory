//
//  UIBezierPath+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIBezierPath (PJCategory)

/**
 根据文字和字体创建贝塞尔路径，不支持表情
 */
+ (nullable UIBezierPath *)bezierPathWithText:(NSString *)text font:(UIFont *)font;

@end

NS_ASSUME_NONNULL_END
