//
//  DogDetailView.swift
//  Dogs
//
//  Created by Sean Tesch on 9/28/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class DogDetailView: UIViewController {
    @IBOutlet weak var dogName: UITextField!
    
    var name: String = ""

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
        
        if segue.identifier == "doneSegue" {
            name = dogName.text!
        }
        
    }

}
