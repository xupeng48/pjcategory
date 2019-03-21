//
//  NSAttributedString+Util.m
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import "NSAttributedString+PJCategory.h"
#import "NSArray+PJCategory.h"

@implementation NSAttributedString (PJCategory)

+ (instancetype)attributeTextWith:(NSArray<NSString *> *)texts colors:(NSArray<UIColor *> *)colors fontSizes:(NSArray<NSNumber *> *)fontSizes{
    NSAssert([texts count] == [colors count], @"Count must be same");
    NSAssert([fontSizes count] == [colors count], @"Count must be same");
    NSArray * fonts = [fontSizes map:^__kindof NSObject *(__kindof NSNumber * fontSize) {
        return [UIFont systemFontOfSize:[fontSize integerValue]];
    }];
    return [self attributeTextWith:texts colors:colors fonts:fonts];
}

+ (instancetype)attributeTextWith:(NSArray<NSString *> *)texts colors:(NSArray<UIColor *> *)colors fonts:(NSArray<UIFont *> *)fonts{
    NSAssert([texts count] == [colors count], @"Count must be same");
    NSAssert([fonts count] == [colors count], @"Count must be same");
    NSMutableAttributedString * result = [NSMutableAttributedString new];
    for (NSInteger index = 0; index < texts.count; index ++) {
        NSString * text = [texts objectAtIndex:index];
        UIColor * color = [colors objectAtIndex:index];
        UIFont * font = [fonts objectAtIndex:index];
        NSDictionary * attributes = @{
                                      NSForegroundColorAttributeName : color,
                                      NSFontAttributeName : font
                                      };
        NSAttributedString * attr = [[NSAttributedString alloc] initWithString:text
                                                                    attributes:attributes];
        [result appendAttributedString:attr];
    }
    return result;
}
@end
