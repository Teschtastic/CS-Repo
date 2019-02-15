//
//  ThirdViewController.swift
//  Canada
//
//  Created by Sean Tesch on 9/29/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ThirdViewController: UIViewController {
    @IBOutlet weak var amount: UITextField!
    @IBOutlet weak var american: UIButton!
    @IBOutlet weak var canadian: UIButton!
    
    
            /*let alertController = UIAlertController(title: "Hey CSCI 351", message: "Do you want a quiz on Friday?", preferredStyle: .Alert)
            let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
            alertController.addAction(defaultAction)
            presentViewController(alertController, animated: true, completion: nil) */
   
    @IBAction func americanButton(sender: UIButton) {
        let USD = Double(amount.text!)
        let CAD = USD! / 1.34170
        
        let alertController = UIAlertController(title: "American Dollars", message: "The amount of American dollars is: " + "$" + String(format: "%.2f", CAD), preferredStyle: .Alert)
        let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
        alertController.addAction(defaultAction)
        presentViewController(alertController, animated: true, completion: nil)
    }
    @IBAction func canadianButton(sender: UIButton) {
        let CAD = Double(amount.text!)
        let USD = CAD! / 0.745322
        
        let alertController = UIAlertController(title: "Canadian Dollars", message: "The amount of Canadian dollars is: " + "$" + String(format: "%.2f", USD), preferredStyle: .Alert)
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
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        self.view.endEditing(true)
    }
    
}
