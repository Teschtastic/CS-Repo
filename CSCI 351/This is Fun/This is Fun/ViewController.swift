//
//  ViewController.swift
//  This is Fun
//
//  Created by Sean Tesch on 9/8/15.
//  Copyright (c) 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var DisappearingLabel: UILabel!
    
    @IBAction func HideButton(sender: UIButton) {
        DisappearingLabel.hidden = true
    }
    @IBAction func ShowButton(sender: UIButton) {
        DisappearingLabel.hidden = false
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

