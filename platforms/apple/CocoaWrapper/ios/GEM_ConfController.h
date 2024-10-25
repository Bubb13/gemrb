/* GemRB - Infinity Engine Emulator
 * Copyright (C) 2011 The GemRB Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *
 */

#import <UIKit/UIKit.h>

@protocol GEM_ConfControllerDelegate
- (void)setupComplete:(NSString*)configPath;
@end

@interface GEM_NavController : UINavigationController {
@private
}
	@end

	@interface GEM_ConfController : NSObject <UINavigationControllerDelegate> {
	@private

		NSString* docDir;
		NSArray* configFiles;
		NSArray* installFiles;
		NSArray* installedGames;
		NSArray* logFiles;

		NSArray* toolBarItems;

		NSIndexPath* configIndexPath;

		UITextView* editor;
		UITableView* controlTable;

		UINavigationController* rootVC;
		UIViewController* editorVC;

		UIBarButtonItem* editorButton;
		UIBarButtonItem* playButton;
	}
	@property(nonatomic, retain) IBOutlet UITableView* controlTable;
	@property(nonatomic, retain) NSIndexPath* configIndexPath;
	@property(nonatomic, retain) IBOutlet UITextView* editor;
	@property(nonatomic, retain) IBOutlet UINavigationController* rootVC;
	@property(nonatomic, retain) IBOutlet UIViewController* editorVC;
	@property(nonatomic, retain) IBOutlet UIBarButtonItem* playButton;
	@property(nonatomic, retain) id delegate;

	- (void)reloadTableData;
	- (NSString*)selectedConfigPath;
	- (BOOL)installGame:(NSIndexPath*)indexPath;

	- (NSInteger)numberOfSectionsInTableView:(UITableView*)tableView;
	- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath;
	- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section;
	- (NSString*)tableView:(UITableView*)tableView titleForHeaderInSection:(NSInteger)section;
	- (void)tableView:(UITableView*)tableView didDeselectRowAtIndexPath:(NSIndexPath*)indexPath;
	- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath;

	- (IBAction)saveConfig:(id)sender;
	- (IBAction)launchGEM:(id)sender;

	- (void)navigationController:(UINavigationController*)navigationController willShowViewController:(UIViewController*)viewController animated:(BOOL)animated;
	@end
