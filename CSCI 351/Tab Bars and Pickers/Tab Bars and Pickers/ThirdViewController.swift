//
//  ThirdViewController.swift
//  Tab Bars and Pickers
//
//  Created by Sean Tesch on 9/25/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ThirdViewController: UIViewController, UIPickerViewDataSource, UIPickerViewDelegate {
    @IBOutlet weak var foodLabel: UILabel!
    
    let entreePart = 0
    let sidePart = 1
    var entreePicked = ""
    var sidePicked = ""
    var entrees = ["Burger", "Fish", "Steak", "Pizza"]
    var sides = ["Fries", "Salad", "Soup"]
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return 2
    }
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        if (component == entreePart) {
            return entrees.count
        }
        else {
            return sides.count
        }
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        if (component == entreePart) {
            return entrees[row]
        }
        else {
            return sides[row]
        }
    }
    
    func pickerView(pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        if (component == entreePart) {
            entreePicked = entrees[row]
        }
        else if (component == sidePart) {
            sidePicked = sides[row]
        }
        
        foodLabel.text = entreePicked + " with " + sidePicked
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        sidePicked = sides[0]
        entreePicked = entrees[0]
        foodLabel.text = entreePicked + " with " + sidePicked
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}