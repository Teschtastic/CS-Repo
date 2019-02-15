//
//  ViewController.swift
//  Activity View
//
//  Created by Sean Tesch on 10/28/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITextFieldDelegate {
    
    var mood = ""

    @IBOutlet weak var textBox: UITextField!
    
    @IBAction func share(sender: AnyObject) {
        mood = textBox.text!
        let myShare = "I am feeling " + mood + " today."
        let activityVC: UIActivityViewController = UIActivityViewController(activityItems: [myShare], applicationActivities: nil)
        presentViewController(activityVC, animated: true, completion: nil)
    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        textBox.resignFirstResponder()
        return true
    }
    
    override func touchesEnded(touches: Set<UITouch>, withEvent event: UIEvent?) {
        textBox.resignFirstResponder()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        textBox.delegate = self
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

