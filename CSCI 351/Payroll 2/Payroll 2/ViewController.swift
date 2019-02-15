//
//  ViewController.swift
//  Payroll 2
//
//  Created by Sean Tesch on 9/17/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var empName: UITextView!
    @IBOutlet weak var rateLabel: UILabel!
    @IBOutlet weak var hourLabel: UILabel!
    @IBOutlet weak var rateStep: UIStepper!
    @IBOutlet weak var hourStep: UIStepper!
    @IBOutlet weak var nameLabel: UILabel!
    
    @IBAction func rateStepper(sender: UIStepper) {
        let progress = sender.value
        rateLabel.text = String(stringInterpolationSegment: progress)
    }
    
    @IBAction func hourStepper(sender: UIStepper) {
        let progress = sender.value
        hourLabel.text = String(stringInterpolationSegment: progress)
    }
    
    @IBAction func computeButton(sender: UIButton) {
        let name = empName.text
        let hours = Double(hourLabel.text!)
        let hours1 = 40.0
        let hours2 = 50.0
        let rate = Double(rateLabel.text!)
        var pay:Double
        var overPay:Double
        var totalPay:Double
        var totalPay1:Double
        
        if (hours <= 40) {
            
            totalPay = hours! * rate!
            
            let alertController = UIAlertController(title: "Employee pay", message: nil, preferredStyle: .Alert)
            alertController.message = "The weekly pay for " + name + " was: " + String(format: "%.2f", totalPay);
            let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
            alertController.addAction(defaultAction)
            presentViewController(alertController, animated: true, completion: nil)
            
            
        } else if (hours > 40 && hours <= 50) {
            
            let overtimeHours1 = hours! - 40.0
            let overtimeRate1 = rate! * 1.5
            
            pay = (hours1 * rate!)
            overPay = (overtimeHours1 * overtimeRate1)
            totalPay = pay + overPay
            
            let alertController = UIAlertController(title: "Employee pay", message: nil, preferredStyle: .Alert)
            alertController.message = "The weekly pay for " + name + " was: " + String(format: "%.2f", totalPay);
            let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
            alertController.addAction(defaultAction)
            presentViewController(alertController, animated: true, completion: nil)
            
        } else if (hours > 50) {
            
            let overtimeHours = 10.0
            let overtimeRate = rate! * 1.5
            
            pay = (hours1 * rate!)
            overPay = (overtimeHours * overtimeRate)
            totalPay1 = pay + overPay
            
            let overtimeHours2 = hours! - 50.0
            let overtimeRate2 = rate! * 2
            
            pay = (hours2 * rate!)
            overPay = (overtimeHours2 * overtimeRate2)
            totalPay = totalPay1 + overPay
            
            let alertController = UIAlertController(title: "Employee pay", message: nil, preferredStyle: .Alert)
            alertController.message = "The weekly pay for " + name + " was: " + String(format: "%.2f", totalPay);
            let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
            alertController.addAction(defaultAction)
            presentViewController(alertController, animated: true, completion: nil)
            
        }
        
    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        empName.resignFirstResponder()
        self.view.endEditing(true)
        return true
    }
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        self.view.endEditing(true)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        hourStep.wraps = true
        hourStep.autorepeat = true
        hourStep.value = 20.0
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}
