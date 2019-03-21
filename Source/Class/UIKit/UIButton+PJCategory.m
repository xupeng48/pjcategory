//
//  UIButton+PJCategory.m
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import "UIButton+PJCategory.h"
#import "UIImage+PJCategory.h"

@implementation UIButton (PJCategory)

- (void)setBackgroundColor:(UIColor *)color forState:(UIControlState)state {
    [self setBackgroundImage:[UIImage imageWithColor:color] forState:state];
}

@end
