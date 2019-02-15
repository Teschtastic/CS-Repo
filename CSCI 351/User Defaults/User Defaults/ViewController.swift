//
//  ViewController.swift
//  User Defaults
//
//  Created by Sean Tesch on 11/4/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var ageField: UITextField!
    
    @IBAction func saveButton(sender: AnyObject) {
        let defaults = NSUserDefaults.standardUserDefaults()
        defaults.setObject(nameField.text!, forKey: "theName")
        let age = Int(ageField.text!)
        defaults.setInteger(age!, forKey: "theAge")
        
        nameField.text = ""
        ageField.text = ""
    }
    
    @IBAction func retieveButton(sender: AnyObject) {
        let defaults = NSUserDefaults.standardUserDefaults()
        if let name = defaults.stringForKey("theName") {
           nameField.text = name
        }
        if let age = defaults.stringForKey("theAge") {
            ageField.text = age
            let num = Int(age)
        }
        
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

