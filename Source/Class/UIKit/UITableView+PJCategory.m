//
//  UITableView+PJCategory.m
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import "UITableView+PJCategory.h"

@implementation UITableView (PJCategory)

- (void)updateWithBlock:(void (^)(UITableView *tableView))block {
    [self beginUpdates];
    block(self);
    [self endUpdates];
}

- (void)scrollToRow:(NSUInteger)row inSection:(NSUInteger)section atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated {
    @try {
        NSIndexPath *indexPath = [NSIndexPath indexPathForRow:row inSection:section];
        [self scrollToRowAtIndexPath:indexPath atScrollPosition:scrollPosition animated:animated];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
}

- (void)insertRowAtIndexPath:(NSIndexPath *)indexPath withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        [self insertRowsAtIndexPaths:@[indexPath] withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
}

- (void)insertRow:(NSUInteger)row inSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        NSIndexPath *toInsert = [NSIndexPath indexPathForRow:row inSection:section];
        [self insertRowAtIndexPath:toInsert withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
}

- (void)reloadRowAtIndexPath:(NSIndexPath *)indexPath withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        [self reloadRowsAtIndexPaths:@[indexPath] withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
}

- (void)reloadRow:(NSUInteger)row inSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        NSIndexPath *toReload = [NSIndexPath indexPathForRow:row inSection:section];
        [self reloadRowAtIndexPath:toReload withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
}

- (void)deleteRowAtIndexPath:(NSIndexPath *)indexPath withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        [self deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
}

- (void)deleteRow:(NSUInteger)row inSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        NSIndexPath *toDelete = [NSIndexPath indexPathForRow:row inSection:section];
        [self deleteRowAtIndexPath:toDelete withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
}

- (void)insertSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        NSIndexSet *sections = [NSIndexSet indexSetWithIndex:section];
        [self insertSections:sections withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
    
}

- (void)deleteSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        NSIndexSet *sections = [NSIndexSet indexSetWithIndex:section];
        [self deleteSections:sections withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
    
}

- (void)reloadSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation {
    @try {
        NSIndexSet *indexSet = [NSIndexSet indexSetWithIndex:section];
        [self reloadSections:indexSet withRowAnimation:animation];
    } @catch (NSException *exception) {
        NSLog(@"catch error: %@", exception.description);
    }
}

- (void)clearSelectedRowsAnimated:(BOOL)animated {
    NSArray *indexs = [self indexPathsForSelectedRows];
    [indexs enumerateObjectsUsingBlock:^(NSIndexPath* path, NSUInteger idx, BOOL *stop) {
        [self deselectRowAtIndexPath:path animated:animated];
    }];
}

- (CGRect)pj_rectForHeaderInSection:(NSInteger)section {
    CGRect rect = CGRectZero;
    if (section < [self numberOfSections]) {
        @try {
            rect = [self rectForHeaderInSection:section];
        } @catch (NSException *exception) {
            NSLog(@"catch error: %@", exception);
        }
    }
    return rect;
}

@end
