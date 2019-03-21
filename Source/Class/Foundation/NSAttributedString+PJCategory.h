//
//  longValueForKey
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSAttributedString (PJCategory)

+ (instancetype)attributeTextWith:(NSArray<NSString *> *)texts
                           colors:(NSArray<UIColor *> *)colors
                        fontSizes:(NSArray<NSNumber *> *)fontSizes;

+ (instancetype)attributeTextWith:(NSArray<NSString *> *)texts
                           colors:(NSArray<UIColor *> *)colors
                            fonts:(NSArray<UIFont *> *)fonts;

@end
