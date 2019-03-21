//
//  UITableView+PJCategory.h
//  PJCategory
//
//  Created by peng xu on 2019/3/21.
//  Copyright © 2019 xupeng. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITableView (PJCategory)


/**
 封装了beginUpdates/endUpdates
 */
- (void)updateWithBlock:(void (^)(UITableView *tableView))block;

/**
 滚动到指定位置
 */
- (void)scrollToRow:(NSUInteger)row inSection:(NSUInteger)section atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;

/**
 tableView中插入一行
 
 note: 需要额外维护数据源，这个函数只操作UI
 */
- (void)insertRow:(NSUInteger)row inSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation;


/**
 reload tableView一行
 */
- (void)reloadRow:(NSUInteger)row inSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation;

/**
 tableView中删除一行
 
 note: 需要额外维护数据源，这个函数只操作UI
 */
- (void)deleteRow:(NSUInteger)row inSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation;

/**
 tableView中插入一行
 
 note: 需要额外维护数据源，这个函数只操作UI
 */
- (void)insertRowAtIndexPath:(NSIndexPath *)indexPath withRowAnimation:(UITableViewRowAnimation)animation;

/**
 reload一个IndexPath
 
 note: 需要额外维护数据源，这个函数只操作UI
 */
- (void)reloadRowAtIndexPath:(NSIndexPath *)indexPath withRowAnimation:(UITableViewRowAnimation)animation;

/**
 tableView中删除一个indexPath
 
 note: 需要额外维护数据源，这个函数只操作UI
 */
- (void)deleteRowAtIndexPath:(NSIndexPath *)indexPath withRowAnimation:(UITableViewRowAnimation)animation;


/**
 tableView中插入一个section
 
 note: 需要额外维护数据源，这个函数只操作UI
 */
- (void)insertSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation;

/**
 tableView中删除一个section
 
 note: 需要额外维护数据源，这个函数只操作UI
 */
- (void)deleteSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation;


/**
 tableView中reload一个section
 
 note: 需要额外维护数据源，这个函数只操作UI
 */
- (void)reloadSection:(NSUInteger)section withRowAnimation:(UITableViewRowAnimation)animation;


/**
 取消选中所有的row
 */
- (void)clearSelectedRowsAnimated:(BOOL)animated;

/**
 安全获取对应section头部rect
 
 note: 失败返回CGRectZero
 */
- (CGRect)pj_rectForHeaderInSection:(NSInteger)section;

@end

NS_ASSUME_NONNULL_END
