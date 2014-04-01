//
//  ViewController.m
//  OpenglES
//
//  Created by Mikhail Radaev on 10.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#import "ViewController.h"
#import "ESView.h"

@interface ViewController ()
@property(nonatomic,strong) ESView* viewOpenGL;
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    if(self.viewOpenGL == nil)
    {
        
        
        self.viewOpenGL = [ESView defaultESView];
        [self.view addSubview:self.viewOpenGL];
    }
    
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
