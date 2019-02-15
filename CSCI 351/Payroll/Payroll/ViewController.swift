//
//  ViewController.swift
//  Payroll
//
//  Created by Sean Tesch on 9/11/15.
//  Copyright (c) 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var nameBox: UITextField!
    @IBOutlet weak var hourBox: UITextField!
    @IBOutlet weak var rateBox: UITextField!
    @IBOutlet weak var payrollLabel: UILabel!
    @IBAction func payButton(sender: AnyObject) {
        
        let name = nameBox.text! + ": $"
        let hours = Int(hourBox.text!)
        let rate = Double(rateBox.text!)
        let pay = Double(hours!) * rate!
        let label = name + String(pay)
        
        payrollLabel.text = label
        payrollLabel.hidden = false
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        self.view.endEditing(true)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

