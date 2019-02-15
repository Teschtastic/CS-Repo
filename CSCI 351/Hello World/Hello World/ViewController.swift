//
//  ViewController.swift
//  Hello World
//
//  Created by Sean Tesch on 9/2/15.
//  Copyright (c) 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController
{

    @IBOutlet weak var TheLabel: UILabel!
    @IBOutlet weak var TheLabel2: UILabel!
    
    @IBAction func TheButtonPressed(sender: AnyObject)
    {
        
        if TheLabel2.hidden == true
        {
            TheLabel2.hidden = false
        }
        else
        {
            TheLabel2.hidden = true
        }
        // When the button is pressed, the label is hidden, then
        // when it is pressed again, the label becomes visible
    }
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning()
    {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

