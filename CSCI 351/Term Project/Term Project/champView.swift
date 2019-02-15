//
//  champView.swift
//  Term Project
//
//  Created by Sean Tesch on 12/2/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import CoreData

class champView: UIViewController, UITableViewDataSource, UITableViewDelegate {
    @available(iOS 2.0, *)
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        <#code#>
    }

    @IBOutlet var champTable: UITableView!
    
    var champion = [NSManagedObject]()
    
    var champions = [
        ("Aatrox"), ("Ahri"), ("Akali"), ("Alistar"), ("Amumu"), ("Anivia"), ("Annie"), ("Ashe"),
        ("Azir"), ("Bard"), ("Blitzcrank"), ("Brand"), ("Braum"), ("Caitlyn"), ("Cassiopeia"),
        ("Cho'Gath"), ("Corki"), ("Darius"), ("Diana"), ("Dr. Mundo"), ("Draven"), ("Ekko"), ("Elise"),
        ("Evelynn"), ("Ezreal"), ("Fiddlesticks"), ("Fiora"), ("Fizz"), ("Galio"), ("Gangplank"),
        ("Garen"), ("Gnar"), ("Gragas"), ("Graves"), ("Hecarim"), ("Heimerdinger"), ("Illaoi"),
        ("Irelia"), ("Janna"), ("Jarvan IV"), ("Jax"), ("Jayce"), ("Jinx"), ("Kalista"), ("Karma"),
        ("Karthus"), ("Kassadin"), ("Katarina"), ("Kayle"), ("Kennen"), ("Kha'Zix"), ("Kindred"),
        ("Kog'Maw"), ("LeBlanc"), ("Lee Sin"), ("Leona"), ("Lissandra"), ("Lucian"), ("Lulu"), ("Lux"),
        ("Malphite"), ("Malzahar"), ("Maokai"), ("Master Yi"), ("Miss Fortune"), ("Mordekaiser"),
        ("Morgana"), ("Nami"), ("Nasus"), ("Nautilus"), ("Nidalee"), ("Nocturne"), ("Nunu"), ("Olaf"),
        ("Orianna"), ("Pantheon"), ("Poppy"), ("Quinn"), ("Rammus"), ("Rek'Sai"), ("Renekton"), ("Rengar"),
        ("Riven"), ("Rumble"), ("Ryze"), ("Sejuani"), ("Shaco"), ("Shen"), ("Shyvana"), ("Singed"), ("Sion"),
        ("Sivir"), ("Skarner"), ("Sona"), ("Soraka"), ("Swain"), ("Syndra"), ("Tahm Kench"), ("Talon"),
        ("Taric"), ("Teemo"), ("Thresh"), ("Tristana"), ("Trundle"), ("Tryndamere"), ("Twisted Fate"), ("Twitch"),
        ("Udyr"), ("Urgot"), ("Varus"), ("Vayne"), ("Veigar"), ("Vel'Koz"), ("Vi"), ("Viktor"), ("Vladimir"),
        ("Volibear"), ("Warwick"), ("Wukong"), ("Xerath"), ("Xin Zhao"), ("Yasuo"), ("Yorick"), ("Zac"),
        ("Zed"), ("Ziggs"), ("Zilean"), ("Zyra")]
    
    var logoImages: [UIImage] = [
        UIImage(named: "Aatrox.png")!, UIImage(named: "Ahri.png")!, UIImage(named: "Akali.png")!, UIImage(named: "Alistar.png")!,
        UIImage(named: "Amumu.png")!, UIImage(named: "Anivia.png")!, UIImage(named: "Annie.png")!, UIImage(named: "Ashe.png")!, UIImage(named: "Azir.png")!,
        UIImage(named: "Bard.png")!, UIImage(named: "Blitzcrank.png")!, UIImage(named: "Brand.png")!, UIImage(named: "Braum.png")!, UIImage(named: "Caitlyn.png")!,
        UIImage(named: "Cassiopeia.png")!, UIImage(named: "Chogath.png")!, UIImage(named: "Corki.png")!, UIImage(named: "Darius.png")!,
        UIImage(named: "Diana.png")!, UIImage(named: "DrMundo.png")!, UIImage(named: "Draven.png")!, UIImage(named: "Ekko.png")!, UIImage(named: "Elise.png")!,
        UIImage(named: "Evelynn.png")!, UIImage(named: "Ezreal.png")!, UIImage(named: "Fiddlesticks.png")!, UIImage(named: "Fiora.png")!, UIImage(named: "Fizz.png")!,
        UIImage(named: "Galio.png")!, UIImage(named: "Gangplank.png")!, UIImage(named: "Garen.png")!, UIImage(named: "Gnar.png")!, UIImage(named: "Gragas.png")!,
        UIImage(named: "Graves.png")!, UIImage(named: "Hecarim.png")!, UIImage(named: "Heimerdinger.png")!, UIImage(named: "Illaoi.png")!, UIImage(named: "Irelia.png")!,
        UIImage(named: "Janna.png")!, UIImage(named: "JarvanIV.png")!, UIImage(named: "Jax.png")!, UIImage(named: "Jayce.png")!, UIImage(named: "Jinx.png")!,
        UIImage(named: "Kalista.png")!, UIImage(named: "Karma.png")!, UIImage(named: "Karthus.png")!, UIImage(named: "Kassadin.png")!, UIImage(named: "Katarina.png")!,
        UIImage(named: "Kayle.png")!, UIImage(named: "Kennen.png")!, UIImage(named: "Khazix.png")!, UIImage(named: "Kindred.png")!, UIImage(named: "KogMaw.png")!,
        UIImage(named: "Leblanc.png")!, UIImage(named: "LeeSin.png")!, UIImage(named: "Leona.png")!, UIImage(named: "Lissandra.png")!, UIImage(named: "Lucian.png")!,
        UIImage(named: "Lulu.png")!, UIImage(named: "Lux.png")!, UIImage(named: "Malphite.png")!, UIImage(named: "Malzahar.png")!, UIImage(named: "Maokai.png")!,
        UIImage(named: "MasterYi.png")!, UIImage(named: "MissFortune.png")!, UIImage(named: "Mordekaiser.png")!, UIImage(named: "Morgana.png")!, UIImage(named: "Nami.png")!,
        UIImage(named: "Nasus.png")!, UIImage(named: "Nautilus.png")!, UIImage(named: "Nidalee.png")!, UIImage(named: "Nocturne.png")!, UIImage(named: "Nunu.png")!,
        UIImage(named: "Olaf.png")!, UIImage(named: "Orianna.png")!, UIImage(named: "Pantheon.png")!, UIImage(named: "Poppy.png")!, UIImage(named: "Quinn.png")!,
        UIImage(named: "Rammus.png")!, UIImage(named: "RekSai.png")!, UIImage(named: "Renekton.png")!, UIImage(named: "Rengar.png")!, UIImage(named: "Riven.png")!,
        UIImage(named: "Rumble.png")!, UIImage(named: "Ryze.png")!, UIImage(named: "Sejuani.png")!, UIImage(named: "Shaco.png")!, UIImage(named: "Shen.png")!,
        UIImage(named: "Shyvana.png")!, UIImage(named: "Singed.png")!, UIImage(named: "Sion.png")!, UIImage(named: "Sivir.png")!, UIImage(named: "Skarner.png")!,
        UIImage(named: "Sona.png")!, UIImage(named: "Soraka.png")!, UIImage(named: "Swain.png")!, UIImage(named: "Syndra.png")!, UIImage(named: "TahmKench.png")!,
        UIImage(named: "Talon.png")!, UIImage(named: "Taric.png")!, UIImage(named: "Teemo.png")!, UIImage(named: "Thresh.png")!, UIImage(named: "Tristana.png")!,
        UIImage(named: "Trundle.png")!, UIImage(named: "Tryndamere.png")!, UIImage(named: "TwistedFate.png")!, UIImage(named: "Twitch.png")!, UIImage(named: "Udyr.png")!,
        UIImage(named: "Urgot.png")!, UIImage(named: "Varus.png")!, UIImage(named: "Vayne.png")!, UIImage(named: "Veigar.png")!, UIImage(named: "Velkoz.png")!,
        UIImage(named: "Vi.png")!, UIImage(named: "Viktor.png")!, UIImage(named: "Vladimir.png")!, UIImage(named: "Volibear.png")!, UIImage(named: "Warwick.png")!,
        UIImage(named: "Wukong.png")!, UIImage(named: "Xerath.png")!, UIImage(named: "XinZhao.png")!, UIImage(named: "Yasuo.png")!, UIImage(named: "Yorick.png")!,
        UIImage(named: "Zac.png")!, UIImage(named: "Zed.png")!, UIImage(named: "Ziggs.png")!, UIImage(named: "Zilean.png")!, UIImage(named: "Zyra.png")!]
    
    func tableView(_ tableView: UITableView,
        numberOfRowsInSection section: Int) -> Int {
        return champions.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell()
        let champs = champions [indexPath.row]
        let champsPic = logoImages [indexPath.row]
        cell.textLabel?.text = champs
        cell.imageView?.image = champsPic
        return cell
    }
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: IndexPath) {
        
        let alert = UIAlertController(title: "New Champion",
            message: "Do you want to add this Champion: \(champions[indexPath.row])?",
            preferredStyle: .alert)
        
        let saveAction = UIAlertAction(title: "Yes",
            style: .default,
            handler: {(action:UIAlertAction) -> Void in
                
                //1
                let appDelegate = UIApplication.shared.delegate as! AppDelegate
                let managedContext = appDelegate.managedObjectContext
                //2
                let entity =  NSEntityDescription.entity(forEntityName: "Champ", in:managedContext)
                let champ = NSManagedObject(entity: entity!, insertInto: managedContext)
                //3
                champ.setValue(self.champions[indexPath.row], forKey: "name")
                //4
                do {
                    try managedContext.save()
                    //5
                    self.champion.append(champ)
                } catch let error as NSError  {
                    print("Could not save \(error), \(error.userInfo)")
                }
        })
        
        let cancelAction = UIAlertAction(title: "No",
            style: .default) { (action: UIAlertAction) -> Void in
        }
        
        alert.addAction(saveAction)
        alert.addAction(cancelAction)
        
        present(alert,
            animated: true,
            completion: nil)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let appDelegate = UIApplication.shared.delegate as! AppDelegate
        let managedContext = appDelegate.managedObjectContext
        let fetchRequest = NSFetchRequest<NSFetchRequestResult>(entityName: "Champ")
        do {
            let results =
            try managedContext.fetch(fetchRequest)
            champion = results as! [NSManagedObject]
        } catch let error as NSError {
            print("Could not fetch \(error), \(error.userInfo)")
        }
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
