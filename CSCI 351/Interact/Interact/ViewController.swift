//
//  ViewController.swift
//  Interact
//
//  Created by Sean Tesch on 9/14/15.
//  Copyright (c) 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITextFieldDelegate {
    
    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var numberField: UITextField!
    @IBOutlet weak var label: UILabel!
    @IBOutlet weak var slideLabel: UILabel!
    @IBOutlet weak var leftSwitch: UISwitch!
    @IBOutlet weak var rightSwitch: UISwitch!
    @IBOutlet weak var somethingButton: UIButton!
    @IBOutlet weak var slider: UISlider!
    @IBOutlet weak var increment: UIStepper!
    
    @IBAction func leftButton(sender: AnyObject) {
        label.text = "Left button was pressed"
        label.hidden = false
    }
    
    @IBAction func rightButton(sender: AnyObject) {
        label.text = "Right button was pressed"
        label.hidden = false
    }
    
    @IBAction func slider(sender: AnyObject) {
        let progress = lroundf(sender.value)
        slideLabel.text = String(progress)
    }
    
    @IBAction func switchChange(sender: UISwitch) {
        let setting = sender.on
        leftSwitch.on = setting
        rightSwitch.on = setting
    }
    
    @IBAction func theSwitcher(sender: UISegmentedControl) {
        if sender.selectedSegmentIndex == 1 {
            leftSwitch.hidden = true
            rightSwitch.hidden = true
            somethingButton.hidden = false
        }
        else {
            leftSwitch.hidden = false
            rightSwitch.hidden = false
            somethingButton.hidden = true
        }
    }
    
    @IBAction func doSomethingButton(sender: UIButton) {
        let alertController = UIAlertController(title: "Hey CSCI 351", message: "Do you want a quiz on Friday?", preferredStyle: .Alert)
        let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
        alertController.addAction(defaultAction)
        presentViewController(alertController, animated: true, completion: nil)
 
    }
    
    @IBAction func increment(sender: UIStepper) {
        let progress = sender.value
        slideLabel.text = String(stringInterpolationSegment: progress)
        // slider.value = increment.value
    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        nameField.resignFirstResponder()
        self.view.endEditing(true)
        return true
    }
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        self.view.endEditing(true)
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        nameField.delegate = self
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

