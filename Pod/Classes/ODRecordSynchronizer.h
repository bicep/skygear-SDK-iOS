//
//  ODRecordSynchronizer.h
//  Pods
//
//  Created by atwork on 12/5/15.
//
//

#import <Foundation/Foundation.h>

@class ODContainer;
@class ODDatabase;
@class ODQuery;
@class ODRecordSynchronizer;
@class ODRecordStorage;
@class ODRecordChange;
@class ODNotification;

/**
 This class handles the network operations required to sync a record storage with remote server.
 */
@interface ODRecordSynchronizer : NSObject

/**
 The <ODContaniner> that this this synchronzier synchronizes with.
 */
@property (nonatomic, readonly, strong) ODContainer *container;

/**
 The <ODDatabase> that this this synchronzier synchronizes with.
 */
@property (nonatomic, readonly, strong) ODDatabase *database;

/**
 The <ODQuery> that this this synchronzier synchronizes with.
 
 Returns <nil> when the synchronizer synchronizes with the entire database.
 */
@property (nonatomic, readonly, strong) ODQuery *query;

/**
 Instantiate an instance of record synchronizer.
 */
- (instancetype)initWithContainer:(ODContainer *)container
                         database:(ODDatabase *)database
                            query:(ODQuery *)query;


/**
 Notifies the synchronizer that update is available to the specified record storage.
 */
- (void)setUpdateAvailableWithRecordStorage:(ODRecordStorage *)storage
                               notification:(ODNotification *)note;

/**
 Instantiate network operations that causes the specified record storage to be updated.
 */
- (void)recordStorageFetchUpdates:(ODRecordStorage *)storage completionHandler:(void(^)(BOOL finished, NSError *error))completionHandler;

/**
 Instantiate network operations that causes the specified changes to be saved.
 */
- (void)recordStorage:(ODRecordStorage *)storage saveChanges:(NSArray *)changes completionHandler:(void(^)(BOOL finished, NSError *error))completionHandler;

- (BOOL)isProcessingChange:(ODRecordChange *)change storage:(ODRecordStorage *)storage;

@end