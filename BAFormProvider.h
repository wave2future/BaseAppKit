/*
 Copyright 2011 Dmitry Stadnik. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are
 permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this list of
 conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice, this list
 of conditions and the following disclaimer in the documentation and/or other materials
 provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY DMITRY STADNIK ``AS IS'' AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DMITRY STADNIK OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those of the
 authors and should not be interpreted as representing official policies, either expressed
 or implied, of Dmitry Stadnik.
*/

#import <UIKit/UIKit.h>
#import "BAFormSectionDescriptor.h"
#import "BAFormLabelFieldCell.h"
#import "BAFormTextFieldCell.h"
#import "BAFormButtonFieldCell.h"

@class BAFormProvider;


@protocol BAFormProviderDelegate <NSObject>

@optional

- (void)decorateLabelFieldCell:(BAFormLabelFieldCell *)cell
					descriptor:(BAFormFieldDescriptor *)descriptor
					 tableView:(UITableView *)tableView;
- (void)decorateTextFieldCell:(BAFormTextFieldCell *)cell
				   descriptor:(BAFormFieldDescriptor *)descriptor
					tableView:(UITableView *)tableView;
- (void)decorateButtonFieldCell:(BAFormButtonFieldCell *)cell
					 descriptor:(BAFormFieldDescriptor *)descriptor
					  tableView:(UITableView *)tableView;

@end


@interface BAFormProvider : NSObject <UITableViewDataSource, UITextFieldDelegate> {
@private
	NSMutableDictionary *_model;
	NSMutableArray *_sectionDescriptors;
	id<BAFormProviderDelegate> _delegate;
}

@property(nonatomic, readonly) NSMutableDictionary *model;
@property(nonatomic, readonly) NSMutableArray *sectionDescriptors;
@property(nonatomic, assign) id<BAFormProviderDelegate> delegate;

- (NSString *)validate;

- (UITableViewCell *)tableView:(UITableView *)tableView
				  cellForField:(BAFormFieldDescriptor *)fieldDescriptor
				   atIndexPath:(NSIndexPath *)indexPath;

@end
