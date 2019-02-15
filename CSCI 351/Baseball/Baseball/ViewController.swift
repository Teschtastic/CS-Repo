//
//  ViewController.swift
//  Baseball
//
//  Created by Sean Tesch on 9/11/15.
//  Copyright (c) 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var hitsBox: UITextField!
    @IBOutlet weak var batsBox: UITextField!
    @IBOutlet weak var averageLabel: UILabel!
    @IBAction func computeButton(sender: AnyObject) {
        
        let hits = Int(hitsBox.text!)
        let atBats = Int(batsBox.text!)
        let average = Double(hits!) / Double(atBats!)
        
        averageLabel.text = String(format: "%.3f", average)
        averageLabel.hidden = false
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

