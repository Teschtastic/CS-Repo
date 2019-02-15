//
//  gameView.swift
//  Term Project
//
//  Created by Sean Tesch on 12/2/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import CoreData

class gameView: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource, UITextFieldDelegate  {
    @available(iOS 2.0, *)
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        <#code#>
    }

    
    @IBOutlet weak var champPicker: UIPickerView!
    @IBOutlet weak var kills: UITextField!
    @IBOutlet weak var deaths: UITextField!
    @IBOutlet weak var assists: UITextField!
    
    var champOwned = [NSManagedObject]()
    var name: String = ""
    var kill: Double = 0
    var death: Double = 0
    var assist: Double = 0
    var killDeath: Double = 0
    var win: Double = 0
    var loss: Double = 0
    var winLoss: Double = 0
    var NAME: String = ""
    
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return champOwned.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        
        let chumps = champOwned[row]
        let matchsize = (chumps.value(forKey: "name") as? String)!
        NAME = String(matchsize)
        return String(matchsize)
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        let chumps = champOwned[row]
        let names = (chumps.value(forKey: "name") as? String)!
        name = String(names)
    }
    
    func addStuff(KILL: Double, DEATH: Double, ASSIST: Double, KILLDEATH: Double, WIN: Double, LOSS: Double, WINLOSS: Double) {
        
        kill = Double(kills.text!)!
        assist = Double(assists.text!)!
        death = Double(deaths.text!)!
        killDeath = Double(kill)/Double(death)
        winLoss = Double(win)/Double(loss)
    }
    
    @IBAction func wonGame(sender: AnyObject) {
        
        win += 1
        addStuff(KILL: kill, DEATH: death, ASSIST: assist, KILLDEATH: killDeath, WIN: win, LOSS: loss, WINLOSS: winLoss)
        saveGame(name: name, kills: kill, deaths: death, assists: assist, kd: killDeath, wins: win, losses: loss, wl: winLoss)
        loadChamp()
        kills.text = ""
        deaths.text = ""
        assists.text = ""
    }
    
    @IBAction func lostGame(sender: AnyObject) {
        
        loss += 1
        addStuff(KILL: kill, DEATH: death, ASSIST: assist, KILLDEATH: killDeath, WIN: win, LOSS: loss, WINLOSS: winLoss)
        saveGame(name: name, kills: kill, deaths: death, assists: assist, kd: killDeath, wins: win, losses: loss, wl: winLoss)
        loadChamp()
        kills.text = ""
        deaths.text = ""
        assists.text = ""
    }
    
    func saveGame(name:String, kills: Double, deaths: Double, assists: Double, kd: Double, wins: Double, losses: Double, wl: Double) {
        
        let appDelegate =
        UIApplication.shared.delegate as! AppDelegate
        let managedContext = appDelegate.managedObjectContext
        let entity =  NSEntityDescription.entity(forEntityName: "Champ", in:managedContext)
        let chump = NSManagedObject(entity: entity!, insertInto: managedContext)
        
        chump.setValue(name, forKey: "name")
        chump.setValue(kills, forKey: "kills")
        chump.setValue(deaths, forKey: "deaths")
        chump.setValue(assists, forKey: "assists")
        chump.setValue(kd, forKey: "kd")
        chump.setValue(wins, forKey: "wins")
        chump.setValue(losses, forKey: "losses")
        chump.setValue(wl, forKey: "wl")
        
        do {
            try managedContext.save()
            //5
            champOwned.append(chump)
        } catch let error as NSError  {
            print("Could not save \(error), \(error.userInfo)")
        }
    }
    
    func loadChamp() {
        
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        let managedContext = appDelegate.managedObjectContext
        let fetchRequest = NSFetchRequest<NSFetchRequestResult>(entityName: "Champ")
        do {
            let results =
            try managedContext.fetch(fetchRequest)
            champOwned = results as! [NSManagedObject]
        } catch let error as NSError {
            print("Could not fetch \(error), \(error.userInfo)")
        }
    }
    
    @IBAction func viewChampStats(sender: AnyObject) {
        
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        let managedContext = appDelegate.managedObjectContext
        let request = NSFetchRequest<NSFetchRequestResult>(entityName: "Champ")
        request.returnsObjectsAsFaults = false
        let keyChamp = self.name
        request.predicate = NSPredicate(format:"name = %@",keyChamp)
        let results: NSArray = try! managedContext.executeFetchRequest(request) as NSArray
        if(results.count > 0)
        {
            let res = results[0] as! NSManagedObject
            let matchkill = res.value(forKey: "kills") as! NSNumber
            let matchdeath = res.value(forKey: "deaths") as! NSNumber
            let matchassist = res.value(forKey: "assists") as! NSNumber
            let matchkd = res.value(forKey: "kd") as! NSNumber
            let matchwin = res.value(forKey: "wins") as! NSNumber
            let matchloss = res.value(forKey: "losses") as! NSNumber
            let matchwl = res.value(forKey: "wl") as! NSNumber
        
            let temp = Double(matchkill)
            let KILL = String(format: "%.0f", temp)
            let temp1 = Double(matchdeath)
            let DEATH = String(format: "%.0f", temp1)
            let temp2 = Double(matchassist)
            let ASSIST = String(format: "%.0f", temp2)
            let temp3 = Double(matchwin)
            let WIN = String(format: "%.0f", temp3)
            let temp4 = Double(matchloss)
            let LOSS = String(format: "%.0f", temp4)
            let temp5 = Double(matchkd)
            let KD = String(format: "%.2f", temp5)
            let temp6 = Double(matchwl)
            let WL = String(format: "%.2f", temp6)
            
            let alertController = UIAlertController(title: "Champion Stats", message:"Your stats are: \n Kills: \(KILL) Deaths: \(DEATH) Assists: \(ASSIST) Kill/Death: \(KD) Wins: \(WIN) Losses: \(LOSS) Win/Loss: \(WL)",preferredStyle: .alert)
            let defaultAction = UIAlertAction(title: "OK", style: .default, handler: nil)
            alertController.addAction(defaultAction)
            present(alertController, animated: true, completion: nil)
            
        }
    }
    
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        kills.resignFirstResponder()
        deaths.resignFirstResponder()
        assists.resignFirstResponder()
        return true
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.view.endEditing(true)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        loadChamp()
        
        champPicker.delegate = self
        champPicker.dataSource = self
        kills.delegate = self
        deaths.delegate = self
        assists.delegate = self
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
