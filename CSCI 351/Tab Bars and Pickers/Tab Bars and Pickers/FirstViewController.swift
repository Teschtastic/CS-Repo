//
//  FirstViewController.swift
//  Tab Bars and Pickers
//
//  Created by Sean Tesch on 9/23/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class FirstViewController: UIViewController {
    @IBOutlet weak var datePicker: UIDatePicker!

    @IBAction func hitMe(sender: AnyObject) {
        let now = datePicker.date
        let dateFormatter = NSDateFormatter()
        
        dateFormatter.dateStyle = NSDateFormatterStyle.ShortStyle
        
        let strDate = dateFormatter.stringFromDate(now)
        
        let alertController = UIAlertController(title: "Tabs are fun!", message: strDate, preferredStyle: .Alert)
        let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
        alertController.addAction(defaultAction)
        presentViewController(alertController, animated: true, completion: nil)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

