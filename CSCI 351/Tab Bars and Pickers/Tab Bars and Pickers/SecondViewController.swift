//
//  SecondViewController.swift
//  Tab Bars and Pickers
//
//  Created by Sean Tesch on 9/23/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController, UIPickerViewDataSource, UIPickerViewDelegate {
    @IBOutlet weak var theLabel: UILabel!
    
    var heroes = ["Boger", "Schemm", "Twig", "Kalata", "Smith"]
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return heroes.count
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return heroes[row]
    }
    
    func pickerView(pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        theLabel.text = heroes[row]
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        theLabel.text = heroes[0]
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

