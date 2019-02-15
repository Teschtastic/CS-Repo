//
//  ViewController.swift
//  Costume Sales
//
//  Created by Sean Tesch on 10/26/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import CoreData

class ViewController: UIViewController, UIPickerViewDataSource, UIPickerViewDelegate, UITextFieldDelegate {
    
    @IBOutlet weak var nameField: UITextField!
    
    let costumePart = 0
    let sizePart = 1
    var costumePicked = ""
    var sizePicked = ""
    var costumes = ["Witch", "Pirate", "Dinosaur", "Pumpkin", "Ghost"]
    var sizes = ["Small", "Medium", "Large", "Extra Large"]
    
    var things = [NSManagedObject]()
    
    func saveOrder(names: String, size: String, costume: String) {
        //1
        let appDelegate =
        UIApplication.sharedApplication().delegate as! AppDelegate
        
        let managedContext = appDelegate.managedObjectContext
        
        //2
        let entity =  NSEntityDescription.entityForName("Order",
            inManagedObjectContext:managedContext)
        
        let order = NSManagedObject(entity: entity!,
            insertIntoManagedObjectContext: managedContext)
        
        //3
        order.setValue(names, forKey: "names")
        order.setValue(size, forKey: "size")
        order.setValue(costume, forKey: "costume")
        
        //4
        do {
            try managedContext.save()
            //5
            things.append(order)
        } catch let error as NSError  {
            print("Could not save \(error), \(error.userInfo)")
        }
    }
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return 2
    }
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        if (component == costumePart) {
            return costumes.count
        }
        else {
            return sizes.count
        }
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        if (component == costumePart) {
            return costumes[row]
        }
        else {
            return sizes[row]
        }
    }
    
    func pickerView(pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        if (component == costumePart) {
            costumePicked = costumes[row]
        }
        else if (component == sizePart) {
            sizePicked = sizes[row]
        }
    }
    
    @IBAction func place(sender: AnyObject) {
        
        saveOrder(nameField.text!, size: sizePicked, costume: costumePicked)
        
        let alertController = UIAlertController(title: "New Customer: " + nameField.text!, message: nil, preferredStyle: .Alert)
        alertController.message = "You ordered a(n) " + sizePicked + " " + costumePicked + " costume. ";
        let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
        alertController.addAction(defaultAction)
        presentViewController(alertController, animated: true, completion: nil)
        
        nameField.text = ""
    }
    
    @IBAction func retrieve(sender: AnyObject) {
        
        let appDelegate = UIApplication.sharedApplication().delegate as! AppDelegate
        let managedContext = appDelegate.managedObjectContext
        let request = NSFetchRequest(entityName: "Order")
        request.returnsObjectsAsFaults = false
        let keyCustomer = nameField.text
        request.predicate = NSPredicate(format:"names = %@",keyCustomer!)
        let results: NSArray = try! managedContext.executeFetchRequest(request)
        if(results.count > 0)
        {
            let res = results[0] as! NSManagedObject
            let matchsize = res.valueForKey("size") as! String
            let matchCostume = res.valueForKey("costume") as! String
            let matchname = res.valueForKey("names") as! String
            
            let alertController = UIAlertController(title: "Order Information", message:"\(matchname) ordered a(n) \(matchsize)  \(matchCostume)  costume.", preferredStyle: .Alert)
            let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
            alertController.addAction(defaultAction)
            presentViewController(alertController, animated: true, completion: nil)
            
            nameField.text = ""
            
        } else {
            
            let alertController = UIAlertController(title: "ERROR:", message:"Name: (\(nameField.text!)) not found.", preferredStyle: .Alert)
            
            let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
            alertController.addAction(defaultAction)
            presentViewController(alertController, animated: true, completion: nil)
            
            nameField.text = ""
        }
    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        nameField.resignFirstResponder()
        return true
    }
    
    override func touchesBegan(touches: Set<UITouch>, withEvent event: UIEvent?) {
        self.view.endEditing(true)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        sizePicked = sizes[0]
        costumePicked = costumes[0]
        nameField.delegate = self
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}

