//
//  SKYSignupUserOperation.h
//  SKYKit
//
//  Copyright 2015 Oursky Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "SKYOperation.h"

/**
 <SKYSignupUserOperation> is a subclass of <SKYOperation> which an user object
 in Ourd. Use this operation to create a new user account in the container.
 When a new user is created, an <NSString> and an <SKYAccessToken>
 will be returned.

 A user account is uniquely identified by an email address given by the user.
 If the user does not provide an email address, you can create an anonymous
 user instead and change the user information to associate an email address
 to this user later.

 A password must be supplied to create an user account in order to protect
 user content. For anonymous user account, you should generate a password
 on the user's behalf and save the password.

 If you assign a block to `signupCompletionBlock`, it will be called when
 the operation is completed.
 */
@interface SKYSignupUserOperation : SKYOperation

/**
 Auth data of the user. The Auth data is a unique dictionary across the system.
 The structure of auth data is defined by the server. Default keys are username and email.
 */
@property (nonatomic, copy) NSDictionary *authData;

/**
 Password given by the user or generated by the application on behalf of the
 user.
 */
@property (nonatomic, copy) NSString *password;

/**
 Profile is the data of user record
 */
@property (nonatomic, copy) NSDictionary *profile;

/**
 Whether the operation is creating an anonymous user account.
 */
@property (nonatomic, readwrite) BOOL anonymousUser;

/**
 The block to execute when the operation completes.

 - *recordID*: An <NSString> object containing the user record identifier.
 - *accessToken*: An <SKYAccessToken> object for performing other operations on behalf of this user.
 - *error*: If an error occurred, this object describes the error.
 */
@property (nonatomic, copy) void (^signupCompletionBlock)
    (SKYUser *user, SKYAccessToken *accessToken, NSError *error);

/**
 Initializes and returns and operation configured to create a user account
 with the specified auth data, password and profile.

 @param authData A dictionary of identifier provided by the user.
 @param password A password provided by the user.
 @param profile A dictionary of data stored in user record.

 @return <SKYSignupUserOperation> object.
 */
+ (instancetype)operationWithAuthData:(NSDictionary *)authData
                             password:(NSString *)password
                              profile:(NSDictionary *)profile;

/**
 Initializes and returns and operation configured to create a user account
 with the specified auth data and password.

 @param authData A dictionary of identifier provided by the user.
 @param password A password provided by the user.

 @return <SKYSignupUserOperation> object.
 */
+ (instancetype)operationWithAuthData:(NSDictionary *)authData password:(NSString *)password;

/**
 Initializes and returns and operation configured to create an anonymous
 user account.

 @return <SKYSignupUserOperation> object.
 */
+ (instancetype)operationWithAnonymousUser;

@end
